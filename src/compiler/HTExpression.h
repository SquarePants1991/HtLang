#ifndef __HTExpression_H_
#define __HTExpression_H_

#include "HTVariable.h"

typedef enum {
    HTExpressionTypeIntLiteral,
    HTExpressionTypeDoubleLiteral,
    HTExpressionTypeBoolLiteral,
    HTExpressionTypeStringLiteral,
    HTExpressionTypeArray,
    HTExpressionTypeIdentifier,
    HTExpressionTypeBinaryOperation,
    HTExpressionTypeFuncCall,
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
    HTExpressionBinaryOperatorLogicAnd,
    HTExpressionBinaryOperatorLogicOr,
    HTExpressionBinaryOperatorCloseRangeArray,
    HTExpressionBinaryOperatorUncloseRangeArray,
} HTExpressionBinaryOperator;

HTClassBegin
    HTExpressionType type;
    union {
        int intVal;
        double doubleVal;
        unsigned char boolVal;
    } value;
    HTStringRef stringVal;
    HTListRef arrayVal;
    HTStringRef identifier;
    struct {
        struct HTExpression * left;
        struct HTExpression * right;
        HTExpressionBinaryOperator operator;
    } binaryOpExpression;
    struct {
        struct HTExpression * identifier;
        HTListRef parameters;
    } funcCallExpression;
HTClassEnd(HTExpression)

static HTStringRef currentCollectingStringLiteral = NULL;

HTExpressionRef HTExpressionCreateIntLiteral(int val);
HTExpressionRef HTExpressionCreateDoubleLiteral(double val);
HTExpressionRef HTExpressionCreateBoolLiteral(unsigned char val);
HTExpressionRef HTExpressionCreateStringLiteral(HTStringRef val);
HTExpressionRef HTExpressionCreateArray(HTListRef val);

void HTExpressionBeginStringLiteral();
void HTExpressionAddStringLiteral(const char *str);
HTExpressionRef HTExpressionEndStringLiteral();

HTExpressionRef HTExpressionCreateIdentifier(HTStringRef val);
HTExpressionRef HTExpressionCreateBinaryOperation(HTExpressionBinaryOperator operator, HTExpressionRef left, HTExpressionRef right);
HTExpressionRef HTExpressionCreateFuncCall(HTExpressionRef identifier, HTListRef parameters);

void HTExpressionPrintDebugInfo(HTExpressionRef expr);

#endif