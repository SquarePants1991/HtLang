#include <compiler/HTStatement.h>
#include "executor/HTExpressionEval.h"

int main() {
    HTStringRef str = HTStringCreateWithChars("Hello");
    HTExpressionRef doubleExpr = HTExpressionCreateDoubleLiteral(20.0);
    HTExpressionRef intExpr = HTExpressionCreateIntLiteral(10);
    HTExpressionRef strExpr = HTExpressionCreateStringLiteral(str);
    HTExpressionRef addExpr1 = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorAdd, doubleExpr, intExpr);
    HTExpressionRef addExpr2 = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorAdd, intExpr, strExpr);

    HTVariableRef result1 = HTExpressionEvaluate(addExpr1, NULL, NULL);
    HTVariableRef result2 = HTExpressionEvaluate(addExpr2, NULL, NULL);
    HTVariablePrintDebugInfo(result1);
    HTVariablePrintDebugInfo(result2);

    HTTypeRelease(str);
    HTTypeRelease(doubleExpr);
    HTTypeRelease(strExpr);
    HTTypeRelease(intExpr);
    HTTypeRelease(addExpr1);
    HTTypeRelease(addExpr2);
    HTTypeRelease(result1);
    HTTypeRelease(result2);

    HTMemPrintAllBlocks();

}