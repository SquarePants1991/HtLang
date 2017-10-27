#include <compiler/HTVariable.h>
#include <compiler/HTExpression.h>
#include <utils/HTDict.h>
#include <utils/HTList.h>
#include "../compiler/HTVariable.h"
#include "../compiler/HTExpression.h"
#include "../compiler/HTFunction.h"

#include "HTExpressionEval.h"
#include "HTExecutor.h"
#include "HTVariableForceConvert.h"


HTVariableRef HTExpressionEvaluate(HTExpressionRef expr, HTRuntimeEnvironmentRef rootEnv) {
    HTVariableRef returnVar = HTVariableCreateWithTypeAndName(HTDataTypeDouble, "_");
    switch(HTPropGet(expr, type)) {
        case HTExpressionTypeIntLiteral:
            HTPropAssignWeak(returnVar, dataType, HTDataTypeInt);
            HTPropAssignWeak(returnVar, value.intValue, HTPropGet(expr, value.intVal))
            break;
        case HTExpressionTypeDoubleLiteral:
            HTPropAssignWeak(returnVar, dataType, HTDataTypeDouble);
            HTPropAssignWeak(returnVar, value.doubleValue, HTPropGet(expr, value.doubleVal));
            break;
        case HTExpressionTypeBoolLiteral:
            HTPropAssignWeak(returnVar, dataType, HTDataTypeBool);
            HTPropAssignWeak(returnVar, value.boolValue, HTPropGet(expr, value.boolVal));
            break;
        case HTExpressionTypeStringLiteral:
            HTPropAssignWeak(returnVar, dataType, HTDataTypeString);
            HTPropAssignStrong(returnVar, stringValue, HTPropGet(expr, stringVal));
            break;
        case HTExpressionTypeArray:
            HTTypeRelease(returnVar);
            returnVar = HTExpressionEvaluateArray(expr, rootEnv);
            break;
        case HTExpressionTypeDict:
            HTTypeRelease(returnVar);
            returnVar = HTExpressionEvaluateDict(expr, rootEnv);
            break;
        case HTExpressionTypeIdentifier:
            HTPropAssignWeak(returnVar, dataType, HTDataTypeDouble);
            HTPropAssignWeak(returnVar, value.doubleValue, 0.0);
            HTVariableRef variable = HTRuntimeEnvironmentGetVariable(rootEnv, HTPropGet(expr, identifier));
            if (variable) {
                HTTypeRelease(returnVar);
                HTTypeRetain(variable);
                return variable;
            }
            break;
        case HTExpressionTypeBinaryOperation:
            HTTypeRelease(returnVar);
            returnVar = HTExpressionEvaluateBinaryOperation(expr, rootEnv);
            break;
        case HTExpressionTypeUnaryOperation:
            HTTypeRelease(returnVar);
            returnVar = HTExpressionEvaluateUnaryOperation(expr, rootEnv);
            break;
        case HTExpressionTypePostfixOperation:
            HTTypeRelease(returnVar);
            returnVar = HTExpressionEvaluatePostfixOperation(expr, rootEnv);
            break;
        case HTExpressionTypeFuncCall:
            HTTypeRelease(returnVar);
            returnVar = HTExpressionEvaluateFuncCall(expr, rootEnv);
            break;
    }
    return returnVar;
}

/** 隐式转换规则。
 * 1. 有一个是字符串，则结果为字符串
 * 2. 有一个是double，则结果为double
 * 3. 否则结果为int
 */
HTVariableRef HTExpressionEvaluateBinaryOperation(HTExpressionRef expr, HTRuntimeEnvironmentRef rootEnv) {
    HTVariableRef result = HTVariableCreateWithTypeAndName(HTDataTypeInt, "_");

    HTExpressionRef leftExpr = HTPropGet(expr, binaryOpExpression.left);
    HTExpressionRef rightExpr = HTPropGet(expr, binaryOpExpression.right);
    HTVariableRef leftResult = HTExpressionEvaluate(leftExpr, rootEnv);
    HTVariableRef rightResult = HTExpressionEvaluate(rightExpr, rootEnv);

    HTDataType leftDataType = HTPropGet(leftResult, dataType);
    HTDataType rightDataType = HTPropGet(rightResult, dataType);
    // TODO: 可操作列表增强，处理数组等情况
    if (leftDataType == HTDataTypeString || rightDataType == HTDataTypeString) {
        HTPropAssignWeak(result, dataType, HTDataTypeString);
        HTVariableConvertToString(leftResult, 1);
        HTVariableConvertToString(rightResult, 1);
    } else if (leftDataType == HTDataTypeDouble || rightDataType == HTDataTypeDouble) {
        HTPropAssignWeak(result, dataType, HTDataTypeDouble);
        HTVariableConvertToDouble(leftResult, 1);
        HTVariableConvertToDouble(rightResult, 1);
    } else if (leftDataType == HTDataTypeInt || rightDataType == HTDataTypeInt) {
        HTPropAssignWeak(result, dataType, HTDataTypeInt);
        HTVariableConvertToInt(leftResult, 1);
        HTVariableConvertToInt(rightResult, 1);
    } else {
        HTPropAssignWeak(result, dataType, HTDataTypeBool);
    }

    HTDataType resultDataType = HTPropGet(result, dataType);
    switch (HTPropGet(expr, binaryOpExpression.operator)) {
        case HTExpressionBinaryOperatorAdd: {
            if (resultDataType == HTDataTypeString) {
                HTStringRef concatStr = HTStringConcat(HTPropGet(leftResult, stringValue),
                                                       HTPropGet(rightResult, stringValue));
                HTPropAssignStrong(result, stringValue, concatStr);
                HTTypeRelease(concatStr);
            } else if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue,
                                 HTPropGet(leftResult, value.doubleValue) + HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue,
                                 HTPropGet(leftResult, value.intValue) + HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) + HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorSub: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue,
                                 HTPropGet(leftResult, value.doubleValue) - HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue,
                                 HTPropGet(leftResult, value.intValue) - HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) - HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorMul: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue,
                                 HTPropGet(leftResult, value.doubleValue) * HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue,
                                 HTPropGet(leftResult, value.intValue) * HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) * HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorDiv: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue,
                                 HTPropGet(leftResult, value.doubleValue) / HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue,
                                 HTPropGet(leftResult, value.intValue) / HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) / HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorMod: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue, (int) HTPropGet(leftResult, value.doubleValue) %
                                                            (int) HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue,
                                 HTPropGet(leftResult, value.intValue) % HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) % HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorPower: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue, pow(HTPropGet(leftResult, value.doubleValue),
                                                                HTPropGet(rightResult, value.doubleValue)));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue,
                                 pow(HTPropGet(leftResult, value.intValue), HTPropGet(rightResult, value.intValue)));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 pow(HTPropGet(leftResult, value.boolValue), HTPropGet(rightResult, value.boolValue)));
            }
            break;
        }
        case HTExpressionBinaryOperatorLogicEqual: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.doubleValue) == HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.intValue) == HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) == HTPropGet(rightResult, value.boolValue));
            } else if (resultDataType == HTDataTypeString) {
                unsigned char isEqual = HTStringEqual(HTPropGet(leftResult, stringValue), HTPropGet(rightResult, stringValue));
                HTPropAssignWeak(result, value.boolValue, isEqual);
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicNotEqual: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.doubleValue) != HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.intValue) != HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) != HTPropGet(rightResult, value.boolValue));
            } else if (resultDataType == HTDataTypeString) {
                unsigned char isEqual = HTStringEqual(HTPropGet(leftResult, stringValue), HTPropGet(rightResult, stringValue));
                HTPropAssignWeak(result, value.boolValue, !isEqual);
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicGreater: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.doubleValue) > HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.intValue) > HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) > HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicGreaterEqual: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.doubleValue) >= HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.intValue) >= HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) >= HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicLess: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.doubleValue) < HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.intValue) < HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) < HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicLessEqual: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.doubleValue) <= HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.intValue) <= HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) <= HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicAnd: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.doubleValue) && HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.intValue) && HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) && HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicOr: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.doubleValue) || HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.intValue) || HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 HTPropGet(leftResult, value.boolValue) || HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorUncloseRangeArray:
        case HTExpressionBinaryOperatorCloseRangeArray: {
            HTListRef arr = HTListCreate();
            if (HTPropGet(leftResult, dataType) == HTDataTypeInt &&
                HTPropGet(rightResult, dataType) == HTDataTypeInt) {
                // Array range must be int
                int rangeStart = HTPropGet(leftResult, value.intValue);
                int rangeEnd = HTPropGet(rightResult, value.intValue);
                if (HTPropGet(expr, binaryOpExpression.operator) == HTExpressionBinaryOperatorCloseRangeArray) {
                    rangeEnd++;
                }
                int step = rangeStart < rangeEnd ? 1 : -1;
                int value = rangeStart;
                while (value < rangeEnd) {
                    HTVariableRef variable = HTVariableCreateWithTypeAndName(HTDataTypeInt, "_");
                    HTPropAssignWeak(variable, value.intValue, value);
                    HTListAppend(arr, variable);
                    HTTypeRelease(variable);
                    value += step;
                }
            }
            HTPropAssignStrong(result, arrayValue, arr);
            HTPropAssignWeak(result, dataType, HTDataTypeArray);

            HTTypeRelease(arr);
            break;
        }
    }

    HTTypeRelease(leftResult);
    HTTypeRelease(rightResult);

    return result;
}

HTVariableRef HTExpressionEvaluatePostfixOperation(HTExpressionRef expr, HTRuntimeEnvironmentRef rootEnv) {
    HTExpressionRef postfixSourceExpr = HTPropGet(expr, postfixOpExpression.expressionSource);
    HTExpressionRef postfixOpExpr = HTPropGet(expr, postfixOpExpression.expressionOp);
    HTVariableRef sourceResult = HTExpressionEvaluate(postfixSourceExpr, rootEnv);
    HTVariableRef opResult = HTExpressionEvaluate(postfixOpExpr, rootEnv);
    HTVariableRef result = NULL;
    switch (HTPropGet(expr, postfixOpExpression.operator)) {
        case HTExpressionPostfixOperatorIndex: {
            if (HTPropGet(sourceResult, dataType) == HTDataTypeMap &&
                    HTPropGet(opResult, dataType) == HTDataTypeString) {
                result = HTDictGet(HTPropGet(sourceResult, dictValue), HTPropGet(opResult, stringValue));
                if (result) {
                    HTTypeRetain(result);
                }
            }
            break;
        }
    }
    // TODO: 默认返回nil
    HTTypeRelease(sourceResult);
    HTTypeRelease(opResult);
    return result;
}

HTVariableRef HTExpressionEvaluateUnaryOperation(HTExpressionRef expr, HTRuntimeEnvironmentRef rootEnv) {
    HTExpressionRef unaryExpr = HTPropGet(expr, unaryOpExpression.expression);
    HTVariableRef exprResult = HTExpressionEvaluate(unaryExpr, rootEnv);
    HTVariableRef result = HTVariableCreateWithTypeAndName(HTPropGet(exprResult, dataType), "_");
    HTDataType resultDataType = HTPropGet(result, dataType);
    switch (HTPropGet(expr, unaryOpExpression.operator)) {
        case HTExpressionUnaryOperatorNeg: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue,
                                 -HTPropGet(exprResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue,
                                 -HTPropGet(exprResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue,
                                 -HTPropGet(exprResult, value.boolValue));
            }
            break;
        }
    }

    HTTypeRelease(exprResult);

    return result;
}

HTVariableRef HTExpressionEvaluateFuncCall(HTExpressionRef expr, HTRuntimeEnvironmentRef rootEnv) {
    HTExpressionRef identifierExpr = HTPropGet(expr, funcCallExpression.identifier);
    HTStringRef funcName = HTPropGet(identifierExpr, identifier);
    HTListNodeRef paramNode = HTPropGet(HTPropGet(expr, funcCallExpression.parameters), head);
    HTListRef paramValueList = HTListCreate();
    while (paramNode) {
        HTVariableRef expressionResult = HTExpressionEvaluate(HTPropGet(paramNode, ptr), rootEnv);
        HTListAppend(paramValueList, expressionResult);
        HTTypeRelease(expressionResult);
        paramNode = HTPropGet(paramNode, next);
    }

    // call func
    HTFunctionRef function = HTRuntimeEnvironmentGetFunction(rootEnv, funcName);
    HTVariableRef returnVal = HTVariableCreateWithTypeAndName(HTDataTypeDouble, "_");

    if (HTPropGet(function, functionType) == HTFunctionTypeLocal) {
        // 执行本地方法
        HTFunctionBody funcBody = HTPropGet(function, u.localFunction.functionBody);
        HTPropAssignWeak(returnVal, value.doubleValue, 0.0);
        if (funcBody) {
            funcBody(paramValueList, returnVal);
        }
    } else {
        // 执行HTLang编写的方法
        HTRuntimeEnvironmentBeginNewEnv(rootEnv);
        HTRuntimeEnvironmentClearStack(rootEnv);
        HTListNodeRef paramNode = HTPropGet(paramValueList, head);
        HTListRef defs = HTPropGet(function, u.customFunction.parameterDefList);
        HTDataType returnType = HTPropGet(function, returnType);
        if (HTListSize(defs) != HTListSize(paramValueList)) {
            printf("参数不匹配\n");
        } else {
            int index = 0;
            while (paramNode) {
                HTVariableRef variableDef =  HTListAt(defs, index);
                HTVariableRef variable = HTPropGet(paramNode, ptr);
                HTRuntimeEnvironmentPushVariableToStack(rootEnv, variable, HTPropGet(variableDef, identifier));
                paramNode = HTPropGet(paramNode, next);
                index++;
            }

            HTExecuteStatementList(HTPropGet(function, u.customFunction.statementList), rootEnv);
            HTVariableRef returnVariable = HTPropGet(rootEnv, returnVariable);
            if (returnVariable) {
                HTTypeRelease(returnVal);
                returnVal = returnVariable;
                HTTypeRetain(returnVal);
            }
        }
        HTRuntimeEnvironmentEndCurrentEnv(rootEnv);
    }

    HTTypeRelease(paramValueList);
    return returnVal;
}

HTVariableRef HTExpressionEvaluateArray(HTExpressionRef expr, HTRuntimeEnvironmentRef rootEnv) {
    HTVariableRef arrayVar = HTVariableCreateWithTypeAndName(HTDataTypeArray, "_");
    HTListRef arrayVarList = HTPropGet(arrayVar, arrayValue);
    HTListRef exprArray = HTPropGet(expr, arrayVal);
    HTListNodeRef node = HTPropGet(exprArray, head);
    while (node) {
        HTVariableRef var = HTExpressionEvaluate(HTPropGet(node, ptr), rootEnv);
        HTListAppend(arrayVarList, var);
        HTTypeRelease(var);
        node = HTPropGet(node, next);
    }
    return arrayVar;
}

HTVariableRef HTExpressionEvaluateDict(HTExpressionRef expr, HTRuntimeEnvironmentRef rootEnv) {
    HTVariableRef mapVar = HTVariableCreateWithTypeAndName(HTDataTypeMap, "_");
    HTDictRef mapVarValue = HTPropGet(mapVar, dictValue);
    HTListRef exprPairList = HTPropGet(expr, dictPairList);
    HTListNodeRef node = HTPropGet(exprPairList, head);
    while (node) {
        HTDictPairRef pair = HTPropGet(node, ptr);
        HTVariableRef key = HTExpressionEvaluate(HTPropGet(pair, key), rootEnv);
        HTVariableRef value = HTExpressionEvaluate(HTPropGet(pair, value), rootEnv);
        HTStringRef keyString = HTPropGet(key, stringValue);
        HTDictSet(mapVarValue, keyString, value);
        HTTypeRelease(key);
        HTTypeRelease(value);
        node = HTPropGet(node, next);
    }
    return mapVar;
}