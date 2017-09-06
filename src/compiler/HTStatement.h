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
	HTExpressionRef conditionExpression;
	HTListRef statementList;
} HTStatementIf;

HTClassBegin
	enum HTStatementType type;
	union {
		HTStatementAssign assignStatement;
		HTStatementDeclare declareStatement;
		HTStatementIf ifStatement;
	} u;
HTClassEnd(HTStatement)

HTStatementRef HTStatementCreateAssign(HTExpressionRef identifier, HTExpressionRef expression);
HTStatementRef HTStatementCreateDeclare(HTVariableRef variable, HTExpressionRef expression);
HTStatementRef HTStatementCreateIf(HTExpressionRef conditionExpression, HTListRef statementList);
void HTStatementPrintDebugInfo(HTStatementRef statement);

#endif