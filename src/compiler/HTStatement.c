#include "HTStatement.h"
#include <stdio.h>

void HTStatementAlloc(HTStatementRef self) {

}

void HTStatementDealloc(HTStatementRef self) {
    switch(self->impl->type) {
        case HTStatementTypeAssign:
            HTPropAssignStrong(self, u.assignStatement.identifier, NULL);
            HTPropAssignStrong(self, u.assignStatement.expression, NULL);
            break;
        case HTStatementTypeDeclare:
            HTPropAssignStrong(self, u.declareStatement.variable, NULL);
            HTPropAssignStrong(self, u.declareStatement.expression, NULL);
            break;
    }
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