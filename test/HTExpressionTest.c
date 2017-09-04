#include "compiler/HTExpression.h"

int main() {
    HTStringRef identifier = HTStringCreateWithChars("Id");
    HTStringRef str = HTStringCreateWithChars("string");

    HTExpressionRef idExpr = HTExpressionCreateIdentifier(identifier);
    HTExpressionRef strExpr = HTExpressionCreateStringLiteral(str);

    HTTypeRelease(identifier);
    HTTypeRelease(str);



    HTExpressionRef doubleExpr = HTExpressionCreateDoubleLiteral(20.0);
    HTExpressionRef intExpr = HTExpressionCreateDoubleLiteral(10);
    HTExpressionRef addExpr = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorAdd, doubleExpr, intExpr);
    HTExpressionBeginStringLiteral();
    HTExpressionAddStringLiteral("Hello");
    HTExpressionRef strLiteral = HTExpressionEndStringLiteral();
    HTMemPrintAllBlocks();

    HTTypeRelease(idExpr);
    HTTypeRelease(strExpr);
    HTTypeRelease(doubleExpr);
    HTTypeRelease(intExpr);
    HTTypeRelease(addExpr);
    HTTypeRelease(strLiteral);
    HTMemPrintAllBlocks();
    return 0;
}