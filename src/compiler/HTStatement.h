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

HTClassBegin
	enum HTStatementType type;
	union {
		HTStatementAssign assignStatement;
		HTStatementDeclare declareStatement;
	} u;
HTClassEnd(HTStatement)

HTStatementRef HTStatementCreateAssign(HTExpressionRef identifier, HTExpressionRef expression);
HTStatementRef HTStatementCreateDeclare(HTVariableRef variable, HTExpressionRef expression);
void HTStatementPrintDebugInfo(HTStatementRef statement);

#endif