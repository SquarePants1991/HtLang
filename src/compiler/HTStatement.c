#include "HTStatement.h"
#include <stdio.h>

HTStatementRef HTStatementCreateAssign(HTExpressionRef identifier, HTExpressionRef expression) {
    HTStatementRef statement = HTMemAlloc(sizeof(HTStatement));
    statement->type = HTStatementTypeAssign;
    statement->u.assignStatement.identifier = identifier;
    statement->u.assignStatement.expression = expression;
    return statement;
}

HTStatementRef HTStatementCreateDeclare(HTVariableRef variable, HTExpressionRef expression) {
    HTStatementRef statement = HTMemAlloc(sizeof(HTStatement));
    statement->type = HTStatementTypeDeclare;
    statement->u.declareStatement.variable = variable;
    statement->u.declareStatement.expression = expression;
    return statement;
}

void HTStatementPrintDebugInfo(HTStatementRef statement) {
    switch (statement->type) {
        case HTStatementTypeAssign:
            printf("Assign Statement!\n");
            break;
        case HTStatementTypeDeclare:
            printf("Declare Statement!\n");
            HTVariablePrintDebugInfo(statement->u.declareStatement.variable);
            break;
        default:
            break;
    }
}