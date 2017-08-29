#include "HTExpression.h"
#include <stdio.h>

HTExpressionRef HTExpressionCreateIntLiteral(int val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeIntLiteral;
    expr->u.intVal = val;
    return expr;
}

HTExpressionRef HTExpressionCreateDoubleLiteral(double val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeDoubleLiteral;
    expr->u.doubleVal = val;
    return expr;
}

HTExpressionRef HTExpressionCreateBoolLiteral(unsigned char val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeBoolLiteral;
    expr->u.boolVal = val;
    return expr;
}

HTExpressionRef HTExpressionCreateStringLiteral(HTStringRef val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeStringLiteral;
    expr->u.stringVal = val;
    return expr;
}

void HTExpressionBeginStringLiteral() {
    currentCollectingStringLiteral = HTStringCreate("");
}

void HTExpressionAddStringLiteral(const char *str) {
    HTStringRef newStr = HTStringCreate(str);
    HTStringRef concatStr = HTStringConcat(currentCollectingStringLiteral, newStr);
    HTStringFree(newStr);
    HTStringFree(currentCollectingStringLiteral);
    currentCollectingStringLiteral = concatStr;
}

HTExpressionRef HTExpressionEndStringLiteral() {
    if (currentCollectingStringLiteral) {
        return HTExpressionCreateStringLiteral(currentCollectingStringLiteral);
    }
    currentCollectingStringLiteral = NULL;
    return HTExpressionCreateStringLiteral(HTStringCreate(""));
}

HTExpressionRef HTExpressionCreateBinaryOperation(HTExpressionBinaryOperator operator, HTExpressionRef left, HTExpressionRef right) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeBinaryOperation;
    expr->u.binaryOpExpression.right = right;
    expr->u.binaryOpExpression.left = left;
    expr->u.binaryOpExpression.operator = operator;
    return expr;
}

HTExpressionRef HTExpressionCreateIdentifier(HTStringRef val) {
    HTExpressionRef expr = HTMemAlloc(sizeof(HTExpression));
    expr->type = HTExpressionTypeIdentifier;
    expr->u.identifier = val;
    return expr;
}

void HTExpressionPrintDebugInfo(HTExpressionRef expr) {
    switch (expr->type) {
        case HTExpressionTypeDoubleLiteral:
            printf("Double Literal: %lf \n", expr->u.doubleVal);
            break;
        case HTExpressionTypeIdentifier:
            printf("Identifier: %s \n", expr->u.stringVal->characters);
            break;
        default:
            break;
    }
}