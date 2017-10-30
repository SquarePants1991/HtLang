#ifndef __HTExpression_H_
#define __HTExpression_H_

#include "HTVariable.h"

typedef enum {
    HTExpressionTypeIntLiteral,
    HTExpressionTypeDoubleLiteral,
    HTExpressionTypeBoolLiteral,
    HTExpressionTypeStringLiteral,
    HTExpressionTypeArray,
    HTExpressionTypeDict,
    HTExpressionTypeIdentifier,
    HTExpressionTypeBinaryOperation,
    HTExpressionTypeUnaryOperation,
    HTExpressionTypePostfixOperation,
    HTExpressionTypeFuncCall,
} HTExpressionType;

typedef enum {
    HTExpressionBinaryOperatorAdd,
    HTExpressionBinaryOperatorSub,
    HTExpressionBinaryOperatorMul,
    HTExpressionBinaryOperatorDiv,
    HTExpressionBinaryOperatorMod,
    HTExpressionBinaryOperatorPower,
    HTExpressionBinaryOperatorLogicNotEqual,
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

typedef enum {
    HTExpressionUnaryOperatorNeg
} HTExpressionUnaryOperator;

typedef enum {
    HTExpressionPostfixOperatorIndex
} HTExpressionPostfixOperator;

HTClassBegin
    HTExpressionType type;
    union {
        int intVal;
        double doubleVal;
        unsigned char boolVal;
    } value;
    HTStringRef stringVal;
    HTListRef arrayVal;
    HTListRef dictPairList;
    HTStringRef identifier;
    struct {
        struct HTExpression * left;
        struct HTExpression * right;
        HTExpressionBinaryOperator operator;
    } binaryOpExpression;
    struct {
        struct HTExpression * expression;
        HTExpressionUnaryOperator operator;
    } unaryOpExpression;
    struct {
        struct HTExpression * expressionSource;
        struct HTExpression * expressionOp;
        HTExpressionPostfixOperator operator;
    } postfixOpExpression;
    struct {
        struct HTExpression * owner;
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
HTExpressionRef HTExpressionCreateDict(HTListRef val);

void HTExpressionBeginStringLiteral();
void HTExpressionAddStringLiteral(const char *str);
HTExpressionRef HTExpressionEndStringLiteral();

HTExpressionRef HTExpressionCreateIdentifier(HTStringRef val);
HTExpressionRef HTExpressionCreateBinaryOperation(HTExpressionBinaryOperator operator, HTExpressionRef left, HTExpressionRef right);
HTExpressionRef HTExpressionCreateUnaryOperation(HTExpressionUnaryOperator operator, HTExpressionRef expression);
HTExpressionRef HTExpressionCreatePostfixOperation(HTExpressionPostfixOperator operator, HTExpressionRef expressionSource, HTExpressionRef expressionOp);
HTExpressionRef HTExpressionCreateFuncCall(HTExpressionRef identifier, HTListRef parameters);
HTExpressionRef HTExpressionCreateMemberFuncCall(HTExpressionRef owner, HTExpressionRef identifier, HTListRef parameters);

void HTExpressionPrintDebugInfo(HTExpressionRef expr);

#endif