#ifndef __HTStatement_H__
#define __HTStatement_H__

#include "HTExpression.h"

enum HTStatementType {
	HTStatementTypeAssign,
	HTStatementTypeDeclare,
	HTStatementTypeIf,
	HTStatementTypeFor,
	HTStatementTypeFuncCall
};

typedef struct {
	HTExpressionRef identifier;
	HTExpressionRef expression;
} HTStatementAssign;

typedef struct {
	HTVariableRef variable;
	HTExpressionRef expression;
} HTStatementDeclare;

typedef struct {
	enum HTStatementType type;
	union {
		HTStatementAssign assignStatement;
		HTStatementDeclare declareStatement;
	} u;
} HTStatement;

typedef HTStatement * HTStatementRef;

static HTStatementRef HTStatementCreateAssign(HTExpressionRef identifier, HTExpressionRef expression) {
	HTStatementRef statement = HTMemAlloc(sizeof(HTStatement));
	statement->type = HTStatementTypeAssign;
	statement->u.assignStatement.identifier = identifier;
	statement->u.assignStatement.expression = expression;
	return statement;
}

static HTStatementRef HTStatementCreateDeclare(HTVariableRef variable, HTExpressionRef expression) {
	HTStatementRef statement = HTMemAlloc(sizeof(HTStatement));
	statement->type = HTStatementTypeDeclare;
	statement->u.declareStatement.variable = variable;
	statement->u.declareStatement.expression = expression;
	return statement;
}

static void HTStatementPrintDebugInfo(HTStatementRef statement) {
	switch (statement->type) {
		case HTStatementTypeAssign:
			printf("Assign Statement!\n");
			break;
		case HTStatementTypeDeclare:
			printf("Declare Statement!\n");
			break;
		default:
			break;
	}
}

#endif