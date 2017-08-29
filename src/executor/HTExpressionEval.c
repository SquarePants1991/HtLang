#include <compiler/HTVariable.h>
#include <compiler/HTExpression.h>
#include "HTExpressionEval.h"

HTVariableRef HTExpressionFindVariable(HTStringRef identifier, HTListRef vars) {
    if (vars) {
        HTListRef node = vars->head;
        while (node != NULL) {
            HTVariableRef variable = node->dataPtr;
            if (variable && HTStringEqual(identifier, variable->identifier)) {
                return variable;
            }
            node = node->next;
        }
    }
    return NULL;
}

HTVariableRef HTExpressionEvaluate(HTExpressionRef expr, HTListRef globalVars, HTListRef localVars) {
    HTVariableRef returnVar = HTVariableCreate(HTDataTypeDouble, "_");
    switch(expr->type) {
        case HTExpressionTypeIntLiteral:
            returnVar->dataType = HTDataTypeInt;
            returnVar->value.intValue = expr->u.intVal;
            break;
        case HTExpressionTypeDoubleLiteral:
            returnVar->dataType = HTDataTypeDouble;
            returnVar->value.doubleValue = expr->u.doubleVal;
            break;
        case HTExpressionTypeBoolLiteral:
            returnVar->dataType = HTDataTypeBool;
            returnVar->value.boolValue = expr->u.boolVal;
            break;
        case HTExpressionTypeStringLiteral:
            returnVar->dataType = HTDataTypeString;
            returnVar->value.stringValue = expr->u.stringVal;
            break;
        case HTExpressionTypeIdentifier:
            returnVar->dataType = HTDataTypeDouble;
            returnVar->value.doubleValue = 0;
            // TODO: 未来会有局部变量的考虑在其中
            HTVariableRef variable = HTExpressionFindVariable(expr->u.stringVal, globalVars);
            if (variable) {
                returnVar->dataType = variable->dataType;
                returnVar->value.doubleValue = variable->value.doubleValue;
            }
            break;
        case HTExpressionTypeBinaryOperation:
            HTVariableFree(returnVar);
            returnVar = HTExpressionEvaluateBinaryOperation(expr, globalVars, localVars);
            break;
    }
    return returnVar;
}

void HTVariableConvertToDouble(HTVariableRef variable) {
    switch (variable->dataType) {
        case HTDataTypeBool:
            variable->value.doubleValue = (double)variable->value.boolValue;
            break;
        case HTExpressionTypeIntLiteral:
            variable->value.intValue = (double)variable->value.intValue;
            break;
    }
    variable->dataType = HTDataTypeDouble;
}

void HTVariableConvertToInt(HTVariableRef variable) {
    switch (variable->dataType) {
        case HTDataTypeBool:
            variable->value.doubleValue = (int)variable->value.boolValue;
            break;
    }
    variable->dataType = HTDataTypeInt;
}

void HTVariableConvertToString(HTVariableRef variable) {
    switch (variable->dataType) {
        case HTDataTypeBool:
            variable->value.stringValue = HTStringCreateFormat("%d", variable->value.boolValue);
            break;
        case HTDataTypeDouble:
            variable->value.stringValue = HTStringCreateFormat("%lf", variable->value.doubleValue);
            break;
        case HTDataTypeInt:
            variable->value.stringValue = HTStringCreateFormat("%d", variable->value.intValue);
            break;
    }
    variable->dataType = HTDataTypeString;
}

/** 隐式转换规则。
 * 1. 有一个是字符串，则结果为字符串
 * 2. 有一个是double，则结果为double
 * 3. 否则结果为int
 */
HTVariableRef HTExpressionEvaluateBinaryOperation(HTExpressionRef expr, HTListRef globalVars, HTListRef localVars) {
    HTVariableRef result = HTVariableCreate(HTDataTypeInt, "_");
    HTExpressionRef leftExpr = expr->u.binaryOpExpression.left;
    HTExpressionRef rightExpr = expr->u.binaryOpExpression.right;
    HTVariableRef leftResult = HTExpressionEvaluate(leftExpr, globalVars, localVars);
    HTVariableRef rightResult = HTExpressionEvaluate(rightExpr, globalVars, localVars);

    if (leftResult->dataType == HTDataTypeString || rightResult->dataType == HTDataTypeString) {
        result->dataType = HTDataTypeString;
        HTVariableConvertToString(leftResult);
        HTVariableConvertToString(rightResult);
    } else if (leftResult->dataType == HTDataTypeDouble || rightResult->dataType == HTDataTypeDouble) {
        result->dataType = HTDataTypeDouble;
        HTVariableConvertToDouble(leftResult);
        HTVariableConvertToDouble(rightResult);
    } else if (leftResult->dataType == HTDataTypeInt || rightResult->dataType == HTDataTypeInt) {
        result->dataType = HTDataTypeInt;
        HTVariableConvertToInt(leftResult);
        HTVariableConvertToInt(rightResult);
    } else {
        result->dataType = HTDataTypeBool;
    }

    switch (expr->u.binaryOpExpression.operator) {
        case HTExpressionBinaryOperatorAdd:
            if (result->dataType == HTDataTypeString) {
                result->value.stringValue = HTStringConcat(leftResult->value.stringValue, rightResult->value.stringValue);
            } else if (result->dataType == HTDataTypeDouble) {
                result->value.doubleValue = leftResult->value.doubleValue + rightResult->value.doubleValue;
            } else if (result->dataType == HTDataTypeInt) {
                result->value.intValue = leftResult->value.intValue + rightResult->value.intValue;
            } else if (result->dataType == HTDataTypeBool) {
                result->value.boolValue = leftResult->value.boolValue + rightResult->value.boolValue;
            }
            break;
        case HTExpressionBinaryOperatorSub:
            if (result->dataType == HTDataTypeDouble) {
                result->value.doubleValue = leftResult->value.doubleValue - rightResult->value.doubleValue;
            } else if (result->dataType == HTDataTypeInt) {
                result->value.intValue = leftResult->value.intValue - rightResult->value.intValue;
            } else if (result->dataType == HTDataTypeBool) {
                result->value.boolValue = leftResult->value.boolValue - rightResult->value.boolValue;
            }
            break;
        case HTExpressionBinaryOperatorMul:
            if (result->dataType == HTDataTypeDouble) {
                result->value.doubleValue = leftResult->value.doubleValue * rightResult->value.doubleValue;
            } else if (result->dataType == HTDataTypeInt) {
                result->value.intValue = leftResult->value.intValue * rightResult->value.intValue;
            } else if (result->dataType == HTDataTypeBool) {
                result->value.boolValue = leftResult->value.boolValue * rightResult->value.boolValue;
            }
            break;
        case HTExpressionBinaryOperatorDiv:
            if (result->dataType == HTDataTypeDouble) {
                result->value.doubleValue = leftResult->value.doubleValue / rightResult->value.doubleValue;
            } else if (result->dataType == HTDataTypeInt) {
                result->value.intValue = leftResult->value.intValue / rightResult->value.intValue;
            } else if (result->dataType == HTDataTypeBool) {
                result->value.boolValue = leftResult->value.boolValue / rightResult->value.boolValue;
            }
            break;
        case HTExpressionBinaryOperatorMod:
            if (result->dataType == HTDataTypeDouble) {
                result->value.doubleValue = (int)(leftResult->value.doubleValue) % (int)(rightResult->value.doubleValue);
            } else if (result->dataType == HTDataTypeInt) {
                result->value.intValue = leftResult->value.intValue % rightResult->value.intValue;
            } else if (result->dataType == HTDataTypeBool) {
                result->value.boolValue = leftResult->value.boolValue % rightResult->value.boolValue;
            }
            break;
        case HTExpressionBinaryOperatorPower:
            if (result->dataType == HTDataTypeDouble) {
                result->value.doubleValue = pow(leftResult->value.doubleValue, rightResult->value.doubleValue);
            } else if (result->dataType == HTDataTypeInt) {
                result->value.intValue = pow(leftResult->value.intValue, rightResult->value.intValue);
            } else if (result->dataType == HTDataTypeBool) {
                result->value.boolValue = pow(leftResult->value.boolValue, rightResult->value.boolValue);
            }
            break;
    }

    return result;
}