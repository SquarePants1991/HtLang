#include "HTStatement.h"
#include <stdio.h>

void HTStatementAlloc(HTStatementRef self) {

}

void HTStatementDealloc(HTStatementRef self) {
    switch(self->impl->type) {
        case HTStatementTypePureExpression:
            HTPropAssignStrong(self, u.pureExpressionStatement.expression, NULL);
            break;
        case HTStatementTypeAssign:
            HTPropAssignStrong(self, u.assignStatement.identifier, NULL);
            HTPropAssignStrong(self, u.assignStatement.expression, NULL);
            break;
        case HTStatementTypeDeclare:
            HTPropAssignStrong(self, u.declareStatement.variable, NULL);
            HTPropAssignStrong(self, u.declareStatement.expression, NULL);
            break;
        case HTStatementTypeIf:
            HTPropAssignStrong(self, u.ifStatement.conditionExpression, NULL);
            HTPropAssignStrong(self, u.ifStatement.statementList, NULL);
            HTPropAssignStrong(self, u.ifStatement.branchStatements, NULL);
            break;
        case HTStatementTypeFuncDef:
            HTPropAssignStrong(self, u.funcDefStatement.identifier, NULL);
            HTPropAssignStrong(self, u.funcDefStatement.parameterDefList, NULL);
            HTPropAssignStrong(self, u.funcDefStatement.statementList, NULL);
            break;
        case HTStatementTypeReturn:
            HTPropAssignStrong(self, u.returnStatement.expression, NULL);
            break;
    }
}

HTStatementRef HTStatementCreatePureExpression(HTExpressionRef expression) {
    HTStatementRef statement = HTStatementCreate();
    HTPropAssignWeak(statement, type, HTStatementTypePureExpression);
    HTPropAssignStrong(statement, u.pureExpressionStatement.expression, expression);
    return statement;
}

HTStatementRef HTStatementCreateAssign(HTExpressionRef identifier, HTExpressionRef expression) {
    HTStatementRef statement = HTStatementCreate();
    HTPropAssignWeak(statement, type, HTStatementTypeAssign);
    HTPropAssignStrong(statement, u.assignStatement.identifier, identifier);
    HTPropAssignStrong(statement, u.assignStatement.expression, expression);
    return statement;
}

HTStatementRef HTStatementCreateDeclare(HTVariableRef variable, HTExpressionRef expression) {
    HTStatementRef statement = HTStatementCreate();
    HTPropAssignWeak(statement, type, HTStatementTypeDeclare);
    HTPropAssignStrong(statement, u.declareStatement.variable, variable);
    HTPropAssignStrong(statement, u.declareStatement.expression, expression);
    return statement;
}

HTStatementRef HTStatementCreateIf(HTExpressionRef conditionExpression, HTListRef statementList, HTIfStatementType ifStatementType) {
    HTStatementRef statement = HTStatementCreate();
    HTPropAssignWeak(statement, type, HTStatementTypeIf);
    HTPropAssignWeak(statement, u.ifStatement.ifStatementType, ifStatementType);
    HTPropAssignStrong(statement, u.ifStatement.conditionExpression, conditionExpression);
    HTPropAssignStrong(statement, u.ifStatement.statementList, statementList);
    if (ifStatementType == HTIfStatementTypeIf) {
        HTListRef branchStatements = HTListCreate();
        HTPropAssignStrong(statement, u.ifStatement.branchStatements, branchStatements);
        HTTypeRelease(branchStatements);
    }
    return statement;
}

void HTStatementSetAsIfBranchStatement(HTStatementRef rootIfStatement, HTStatementRef branchIfStatement) {
    HTListRef branchStatements = HTPropGet(rootIfStatement, u.ifStatement.branchStatements);
    HTListAppend(branchStatements, branchIfStatement);
}

HTStatementRef HTStatementCreateFuncDef(HTExpressionRef identifier, HTListRef parameterDefList, HTListRef statementList, HTDataType returnType) {
    HTStatementRef statement = HTStatementCreate();
    HTPropAssignWeak(statement, type, HTStatementTypeFuncDef);
    HTPropAssignWeak(statement, u.funcDefStatement.returnType, returnType);
    HTPropAssignStrong(statement, u.funcDefStatement.identifier, identifier);
    HTPropAssignStrong(statement, u.funcDefStatement.parameterDefList, parameterDefList);
    HTPropAssignStrong(statement, u.funcDefStatement.statementList, statementList);
    return statement;
}

HTStatementRef HTStatementCreateReturn(HTExpressionRef returnExpr) {
    HTStatementRef statement = HTStatementCreate();
    HTPropAssignWeak(statement, type, HTStatementTypeReturn);
    HTPropAssignStrong(statement, u.returnStatement.expression, returnExpr);
    return statement;
}

void HTStatementPrintDebugInfo(HTStatementRef statement) {
    switch (statement->impl->type) {
        case HTStatementTypeAssign:
            printf("Assign Statement!\n");
            break;
        case HTStatementTypeDeclare:
            printf("Declare Statement!\n");
            HTVariablePrintDebugInfo(statement->impl->u.declareStatement.variable);
            break;
        default:
            break;
    }
}