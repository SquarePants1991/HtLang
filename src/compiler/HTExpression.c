#include "HTExpression.h"
#include "../utils/HTString.h"

void HTExpressionAlloc(HTExpressionRef self) {

}

void HTExpressionDealloc(HTExpressionRef self) {
    HTPropAssignStrong(self, stringVal, NULL);
    HTPropAssignStrong(self, arrayVal, NULL);
    HTPropAssignStrong(self, identifier, NULL);
    HTPropAssignStrong(self, binaryOpExpression.left, NULL);
    HTPropAssignStrong(self, binaryOpExpression.right, NULL);
    HTPropAssignStrong(self, funcCallExpression.identifier, NULL);
    HTPropAssignStrong(self, funcCallExpression.parameters, NULL);
}

HTExpressionRef HTExpressionCreateIntLiteral(int val) {
    HTExpressionRef expr = HTExpressionCreate();
    HTPropAssignWeak(expr, type, HTExpressionTypeIntLiteral);
    HTPropAssignWeak(expr, value.intVal, val);
    return expr;
}

HTExpressionRef HTExpressionCreateDoubleLiteral(double val) {
    HTExpressionRef expr = HTExpressionCreate();
    HTPropAssignWeak(expr, type, HTExpressionTypeDoubleLiteral);
    HTPropAssignWeak(expr, value.doubleVal, val);
    return expr;
}

HTExpressionRef HTExpressionCreateBoolLiteral(unsigned char val) {
    HTExpressionRef expr = HTExpressionCreate();
    HTPropAssignWeak(expr, type, HTExpressionTypeBoolLiteral);
    HTPropAssignWeak(expr, value.boolVal, val);
    return expr;
}

HTExpressionRef HTExpressionCreateStringLiteral(HTStringRef val) {
    HTExpressionRef expr = HTExpressionCreate();
    HTPropAssignWeak(expr, type, HTExpressionTypeStringLiteral);
    HTPropAssignStrong(expr, stringVal, val);
    return expr;
}

HTExpressionRef HTExpressionCreateArray(HTListRef val) {
    HTExpressionRef expr = HTExpressionCreate();
    HTPropAssignWeak(expr, type, HTExpressionTypeArray);
    HTPropAssignStrong(expr, arrayVal, val);
    return expr;
}

void HTExpressionBeginStringLiteral() {
    currentCollectingStringLiteral = HTStringCreateWithChars("");
}

void HTExpressionAddStringLiteral(const char *str) {
    HTStringRef newStr = HTStringCreateWithChars(str);
    HTStringRef concatStr = HTStringConcat(currentCollectingStringLiteral, newStr);
    HTTypeRelease(newStr);
    HTTypeRelease(currentCollectingStringLiteral);
    currentCollectingStringLiteral = concatStr;
}

HTExpressionRef HTExpressionEndStringLiteral() {
    if (currentCollectingStringLiteral) {
        HTExpressionRef expr = HTExpressionCreateStringLiteral(currentCollectingStringLiteral);
        HTTypeRelease(currentCollectingStringLiteral);
        return expr;
    }
    currentCollectingStringLiteral = NULL;
    HTStringRef emptyStr = HTStringCreateWithChars("");
    HTExpressionRef emptyStringExpr = HTExpressionCreateStringLiteral(emptyStr);
    HTTypeRelease(emptyStr);
    return emptyStringExpr;
}

HTExpressionRef HTExpressionCreateBinaryOperation(HTExpressionBinaryOperator operator, HTExpressionRef left, HTExpressionRef right) {
    HTExpressionRef expr = HTExpressionCreate();
    HTPropAssignWeak(expr, type, HTExpressionTypeBinaryOperation);
    HTPropAssignStrong(expr, binaryOpExpression.right, right);
    HTPropAssignStrong(expr, binaryOpExpression.left, left);
    HTPropAssignWeak(expr, binaryOpExpression.operator, operator);
    return expr;
}

HTExpressionRef HTExpressionCreateIdentifier(HTStringRef val) {
    HTExpressionRef expr = HTExpressionCreate();
    HTPropAssignWeak(expr, type, HTExpressionTypeIdentifier);
    HTPropAssignStrong(expr, identifier, val);
    return expr;
}

HTExpressionRef HTExpressionCreateFuncCall(HTExpressionRef identifier, HTListRef parameters) {
    HTExpressionRef expr = HTExpressionCreate();
    HTPropAssignWeak(expr, type, HTExpressionTypeFuncCall);
    HTPropAssignStrong(expr, funcCallExpression.identifier, identifier);
    HTPropAssignStrong(expr, funcCallExpression.parameters, parameters);
    return expr;
}

void HTExpressionPrintDebugInfo(HTExpressionRef expr) {
    switch (expr->impl->type) {
        case HTExpressionTypeDoubleLiteral:
            printf("Double Literal: %lf \n", expr->impl->value.doubleVal);
            break;
        case HTExpressionTypeIdentifier:
            printf("Identifier: %s \n", expr->impl->identifier->impl->characters);
            break;
        default:
            break;
    }
}