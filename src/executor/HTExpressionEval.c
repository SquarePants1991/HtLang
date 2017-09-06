#include <compiler/HTVariable.h>
#include "../compiler/HTExpression.h"
#include "HTExpressionEval.h"


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
        case HTExpressionTypeIdentifier:
            HTPropAssignWeak(returnVar, dataType, HTDataTypeDouble);
            HTPropAssignWeak(returnVar, value.doubleValue, 0.0);
            // TODO: 未来会有局部变量的考虑在其中
            HTVariableRef variable = HTRuntimeEnvironmentGetVariable(rootEnv, HTPropGet(expr, identifier));
            if (variable) {
                HTVaraibleCopyValue(variable, returnVar);
            }
            break;
        case HTExpressionTypeBinaryOperation:
            HTTypeRelease(returnVar);
            returnVar = HTExpressionEvaluateBinaryOperation(expr, rootEnv);
            break;
    }
    return returnVar;
}

void HTVariableConvertToDouble(HTVariableRef variable) {
    switch (HTPropGet(variable, dataType)) {
        case HTDataTypeBool:
            HTPropAssignWeak(variable, value.doubleValue, (double)HTPropGet(variable, value.boolValue));
            break;
        case HTExpressionTypeIntLiteral:
            HTPropAssignWeak(variable, value.doubleValue, (double)HTPropGet(variable, value.intValue));
            break;
    }
    HTPropAssignWeak(variable, dataType, HTDataTypeDouble);
}

void HTVariableConvertToInt(HTVariableRef variable) {
    switch (HTPropGet(variable, dataType)) {
        case HTDataTypeBool:
            HTPropAssignWeak(variable, value.intValue, (double)HTPropGet(variable, value.boolValue));
            break;
    }
    HTPropAssignWeak(variable, dataType, HTDataTypeInt);
}

void HTVariableConvertToString(HTVariableRef variable) {
    switch (HTPropGet(variable, dataType)) {
        case HTDataTypeBool: {
            HTStringRef str = HTStringCreateFormat("%d", HTPropGet(variable, value.boolValue));
            HTPropAssignStrong(variable, stringValue, str);
            HTTypeRelease(str);
            break;
        }
        case HTDataTypeDouble: {
            HTStringRef str = HTStringCreateFormat("%lf", HTPropGet(variable, value.doubleValue));
            HTPropAssignStrong(variable, stringValue, str);
            HTTypeRelease(str);
            break;
        }
        case HTDataTypeInt: {
            HTStringRef str = HTStringCreateFormat("%d", HTPropGet(variable, value.intValue));
            HTPropAssignStrong(variable, stringValue, str);
            HTTypeRelease(str);
            break;
        }
    }
    HTPropAssignWeak(variable, dataType, HTDataTypeString);
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
    if (leftDataType == HTDataTypeString || rightDataType == HTDataTypeString) {
        HTPropAssignWeak(result, dataType, HTDataTypeString);
        HTVariableConvertToString(leftResult);
        HTVariableConvertToString(rightResult);
    } else if (leftDataType == HTDataTypeDouble || rightDataType == HTDataTypeDouble) {
        HTPropAssignWeak(result, dataType, HTDataTypeDouble);
        HTVariableConvertToDouble(leftResult);
        HTVariableConvertToDouble(rightResult);
    } else if (leftDataType == HTDataTypeInt || rightDataType == HTDataTypeInt) {
        HTPropAssignWeak(result, dataType, HTDataTypeInt);
        HTVariableConvertToInt(leftResult);
        HTVariableConvertToInt(rightResult);
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
                HTPropAssignWeak(result, value.doubleValue, HTPropGet(leftResult, value.doubleValue) + HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue, HTPropGet(leftResult, value.intValue) + HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) + HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorSub: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue, HTPropGet(leftResult, value.doubleValue) - HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue, HTPropGet(leftResult, value.intValue) - HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) - HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorMul: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue, HTPropGet(leftResult, value.doubleValue) * HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue, HTPropGet(leftResult, value.intValue) * HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) * HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorDiv: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue, HTPropGet(leftResult, value.doubleValue) / HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue, HTPropGet(leftResult, value.intValue) / HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) / HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorMod: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue, (int)HTPropGet(leftResult, value.doubleValue) % (int)HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue, HTPropGet(leftResult, value.intValue) % HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) % HTPropGet(rightResult, value.boolValue));
            }
            break;
        }
        case HTExpressionBinaryOperatorPower: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.doubleValue, pow(HTPropGet(leftResult, value.doubleValue), HTPropGet(rightResult, value.doubleValue)));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.intValue, pow(HTPropGet(leftResult, value.intValue), HTPropGet(rightResult, value.intValue)));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, pow(HTPropGet(leftResult, value.boolValue), HTPropGet(rightResult, value.boolValue)));
            }
            break;
        }
        case HTExpressionBinaryOperatorLogicEqual: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.doubleValue) == HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.intValue) == HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) == HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicGreater: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.doubleValue) > HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.intValue) > HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) > HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicGreaterEqual: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.doubleValue) >= HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.intValue) >= HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) >= HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicLess: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.doubleValue) < HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.intValue) < HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) < HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
        case HTExpressionBinaryOperatorLogicLessEqual: {
            if (resultDataType == HTDataTypeDouble) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.doubleValue) <= HTPropGet(rightResult, value.doubleValue));
            } else if (resultDataType == HTDataTypeInt) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.intValue) <= HTPropGet(rightResult, value.intValue));
            } else if (resultDataType == HTDataTypeBool) {
                HTPropAssignWeak(result, value.boolValue, HTPropGet(leftResult, value.boolValue) <= HTPropGet(rightResult, value.boolValue));
            }
            HTPropAssignWeak(result, dataType, HTDataTypeBool);
            break;
        }
    }

    HTTypeRelease(leftResult);
    HTTypeRelease(rightResult);

    return result;
}