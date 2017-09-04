#include "compiler/HTStatement.h"

int main() {
    HTStringRef identifier = HTStringCreateWithChars("strVal");
    HTStringRef str = HTStringCreateWithChars("string");

    HTExpressionRef idExpr = HTExpressionCreateIdentifier(identifier);
    HTExpressionRef strExpr = HTExpressionCreateStringLiteral(str);

    HTVariableRef var = HTVariableCreateWithTypeAndName(HTDataTypeString, "strVal");

    HTStatementRef assignStatement = HTStatementCreateAssign(idExpr, strExpr);
    HTStatementRef declareStatement = HTStatementCreateDeclare(var, strExpr);

    HTMemPrintAllBlocks();

    HTTypeRelease(var);
    HTTypeRelease(identifier);
    HTTypeRelease(str);
    HTTypeRelease(idExpr);
    HTTypeRelease(strExpr);

    HTTypeRelease(assignStatement);
    HTTypeRelease(declareStatement);

    HTMemPrintAllBlocks();
}