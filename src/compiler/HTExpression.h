#ifndef __HTExpression_H_
#define __HTExpression_H_

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
    HTExpressionBinaryOperatorLogicEqual,
    HTExpressionBinaryOperatorLogicGreater,
    HTExpressionBinaryOperatorLogicGreaterEqual,
    HTExpressionBinaryOperatorLogicLess,
    HTExpressionBinaryOperatorLogicLessEqual,
} HTExpressionBinaryOperator;

HTClassBegin
    HTExpressionType type;
    union {
        int intVal;
        double doubleVal;
        unsigned char boolVal;
    } value;
    HTStringRef stringVal;
    HTStringRef identifier;
    struct {
        struct HTExpression * left;
        struct HTExpression * right;
        HTExpressionBinaryOperator operator;
    } binaryOpExpression;
HTClassEnd(HTExpression)

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