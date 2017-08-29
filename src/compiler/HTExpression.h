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
    HTExpressionTypeBinaryOperation
} HTExpressionType;

typedef enum {
    HTExpressionBinaryOperatorAdd,
    HTExpressionBinaryOperatorSub,
    HTExpressionBinaryOperatorMul,
    HTExpressionBinaryOperatorDiv,
    HTExpressionBinaryOperatorMod,
    HTExpressionBinaryOperatorPower,
} HTExpressionBinaryOperator;

struct _HTExpression {
    HTExpressionType type;
    union {
        int intVal;
        double doubleVal;
        unsigned char boolVal;
        HTStringRef stringVal;
        HTStringRef identifier;
        struct {
            struct _HTExpression * left;
            struct _HTExpression * right;
            HTExpressionBinaryOperator operator;
        } binaryOpExpression;
    } u;
};

typedef struct _HTExpression HTExpression;
typedef  HTExpression * HTExpressionRef;

static HTStringRef currentCollectingStringLiteral = NULL;

HTExpressionRef HTExpressionCreateIntLiteral(int val);
HTExpressionRef HTExpressionCreateDoubleLiteral(double val);
HTExpressionRef HTExpressionCreateBoolLiteral(unsigned char val);
HTExpressionRef HTExpressionCreateStringLiteral(HTStringRef val);
void HTExpressionBeginStringLiteral();
void HTExpressionAddStringLiteral(const char *str);
HTExpressionRef HTExpressionEndStringLiteral();
HTExpressionRef HTExpressionCreateBinaryOperation(HTExpressionBinaryOperator operator, HTExpressionRef left, HTExpressionRef right);
HTExpressionRef HTExpressionCreateIdentifier(HTStringRef val);
void HTExpressionPrintDebugInfo(HTExpressionRef expr);

#endif