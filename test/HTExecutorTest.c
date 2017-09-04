#include "executor/HTExecutor.h"

int main() {
    HTStringRef identifier = HTStringCreateWithChars("strVal");
    HTStringRef str = HTStringCreateWithChars("hello");
    HTStringRef str2 = HTStringCreateWithChars("world");

    HTExpressionRef idExpr = HTExpressionCreateIdentifier(identifier);
//    HTExpressionRef strExpr = HTExpressionCreateStringLiteral(str);
//    HTExpressionRef strExpr2 = HTExpressionCreateStringLiteral(str2);


    HTVariableRef var = HTVariableCreateWithTypeAndName(HTDataTypeString, "strVal");
//    HTStatementRef declareStatement = HTStatementCreateDeclare(var, strExpr);
//    HTStatementRef assignStatement = HTStatementCreateAssign(idExpr, strExpr2);

    HTCompilerRef compiler = HTCompilerCreate();
//    HTCompilerSetCurrent(compiler);
//    HTCompilerAddStatement(declareStatement);
//    HTCompilerAddStatement(assignStatement);
//
//    HTExecute(compiler);


    HTTypeRelease(var);
    HTTypeRelease(identifier);
    HTTypeRelease(str);
    HTTypeRelease(str2);
    HTTypeRelease(idExpr);
//    HTTypeRelease(strExpr);
//    HTTypeRelease(strExpr2);

//    HTTypeRelease(assignStatement);
//    HTTypeRelease(declareStatement);

    HTTypeRelease(compiler);

    HTMemPrintAllBlocks();
}