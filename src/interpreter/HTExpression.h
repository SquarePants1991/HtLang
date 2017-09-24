#ifndef __HTExpression_H_
#define __HTExpression_H_

#include "../utils/HTString.h"
#include "HTVariable.h"

typedef enum {
    HTExpressionTypeIntLiteral,
    HTExpressionTypeDoubleLiteral,
    HTExpressionTypeBoolLiteral,
    HTExpressionTypeStringLiteral,
    HTExpressionTypeIdentifier,
    HTExpressionTypeBinaryOpAdd,
    HTExpressionTypeBinaryOpSub,
    HTExpressionTypeBinaryOpMul,
    HTExpressionTypeBinaryOpDiv,
} HTExpressionType;

struct _HTExpression {
    HTExpressionType type;
    union {
        int intVal;
        double doubleVal;
        unsigned char boolVal;
    } u;
    HTStringRef stringVal;
    struct _HTExpression * first;
    struct _HTExpression * second;
    struct _HTExpression * third;
};

typedef struct _HTExpression HTExpression;
typedef  HTExpression * HTExpressionRef;

static HTExpressionRef HTExpressionCreateInt(int val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeIntLiteral;
    expr->u.intVal = val;
    return expr;
}

static HTExpressionRef HTExpressionCreateDouble(double val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeDoubleLiteral;
    expr->u.doubleVal = val;
    return expr;
}

static HTExpressionRef HTExpressionCreateBool(unsigned char val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeBoolLiteral;
    expr->u.boolVal = val;
    return expr;
}

static HTExpressionRef HTExpressionCreateString(HTStringRef val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeStringLiteral;
    expr->stringVal = val;
    return expr;
}

static HTExpressionRef HTExpressionCreateIdentifier(HTStringRef val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeIdentifier;
    expr->stringVal = val;
    return expr;
}

static HTExpressionRef HTExpressionAdd(HTExpressionRef left, HTExpressionRef right) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeBinaryOpAdd;
    expr->first = left;
    expr->second = right;
    return expr;
}

static HTExpressionRef HTExpressionSub(HTExpressionRef left, HTExpressionRef right) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeBinaryOpSub;
    expr->first = left;
    expr->second = right;
    return expr;
}

static HTExpressionRef HTExpressionMul(HTExpressionRef left, HTExpressionRef right) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeBinaryOpMul;
    expr->first = left;
    expr->second = right;
    return expr;
}

static HTExpressionRef HTExpressionDiv(HTExpressionRef left, HTExpressionRef right) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeBinaryOpDiv;
    expr->first = left;
    expr->second = right;
    return expr;
}

static HTVariableRef HTExpressionFindVariable(HTStringRef identifier, HTListRef vars) {
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

static HTVariableRef HTExpressionEvaluate(HTExpressionRef expr, HTListRef globalVars, HTListRef localVars) {
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
        case HTExpressionTypeIdentifier:
            returnVar->dataType = HTDataTypeDouble;
            returnVar->value.doubleValue = 0;
            // TODO: 未来会有局部变量的考虑在其中
            HTVariableRef variable = HTExpressionFindVariable(expr->stringVal, globalVars);
            if (variable) {
                returnVar->dataType = variable->dataType;
                returnVar->value.doubleValue = variable->value.doubleValue;
            }
            break;
        case HTExpressionTypeBinaryOpAdd:
            returnVar->dataType = HTDataTypeDouble;
            returnVar->value.doubleValue = HTExpressionEvaluate(expr->first, globalVars, localVars)->value.doubleValue + HTExpressionEvaluate(expr->second, globalVars, localVars)->value.doubleValue;
            break;
        case HTExpressionTypeBinaryOpSub:
            returnVar->dataType = HTDataTypeDouble;
            returnVar->value.doubleValue = HTExpressionEvaluate(expr->first, globalVars, localVars)->value.doubleValue - HTExpressionEvaluate(expr->second, globalVars, localVars)->value.doubleValue;
            break;
        case HTExpressionTypeBinaryOpMul:
            returnVar->dataType = HTDataTypeDouble;
            returnVar->value.doubleValue = HTExpressionEvaluate(expr->first, globalVars, localVars)->value.doubleValue * HTExpressionEvaluate(expr->second, globalVars, localVars)->value.doubleValue;
            break;
        case HTExpressionTypeBinaryOpDiv:
            returnVar->dataType = HTDataTypeDouble;
            returnVar->value.doubleValue = HTExpressionEvaluate(expr->first, globalVars, localVars)->value.doubleValue / HTExpressionEvaluate(expr->second, globalVars, localVars)->value.doubleValue;
            break;
    }
    return returnVar;
}

static void HTExpressionPrintDebugInfo(HTExpressionRef expr) {
    switch (expr->type) {
        case HTExpressionTypeDoubleLiteral:
            printf("Double Literal: %lf \n", expr->u.doubleVal);
            break;
        case HTExpressionTypeIdentifier:
            printf("Identifier: %s \n", expr->stringVal->characters);
            break;
        default:
            break;
    }
}

#endif