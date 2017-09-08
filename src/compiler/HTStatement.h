#ifndef __HTStatement_H__
#define __HTStatement_H__

#include "HTExpression.h"

enum HTStatementType {
	HTStatementTypePureExpression,
	HTStatementTypeAssign,
	HTStatementTypeDeclare,
	HTStatementTypeIf,
	HTStatementTypeFor,
	HTStatementTypeFuncDef,
    HTStatementTypeReturn
};

typedef enum {
	HTIfStatementTypeIf,
	HTIfStatementTypeElif,
	HTIfStatementTypeElse,
} HTIfStatementType;

typedef struct {
	HTExpressionRef expression;
} HTStatementPureExpression;

typedef struct {
	HTExpressionRef identifier;
	HTExpressionRef expression;
} HTStatementAssign;

typedef struct {
	HTVariableRef variable;
	HTExpressionRef expression;
} HTStatementDeclare;

typedef struct {
	HTIfStatementType ifStatementType;
	HTExpressionRef conditionExpression;
	HTListRef statementList;
	HTListRef branchStatements;
} HTStatementIf;

typedef struct {
	HTExpressionRef identifier;
	HTListRef parameterDefList;
	HTListRef statementList;
    HTDataType returnType;
} HTStatementFuncDef;

typedef struct {
    HTExpressionRef expression;
} HTStatementReturn;

typedef struct {
	HTExpressionRef expression;
} HTStatementFor;


HTClassBegin
	enum HTStatementType type;
	union {
		HTStatementPureExpression pureExpressionStatement;
		HTStatementAssign assignStatement;
		HTStatementDeclare declareStatement;
		HTStatementIf ifStatement;
		HTStatementFuncDef funcDefStatement;
        HTStatementReturn returnStatement;
	} u;
HTClassEnd(HTStatement)

HTStatementRef HTStatementCreatePureExpression(HTExpressionRef expression);
HTStatementRef HTStatementCreateAssign(HTExpressionRef identifier, HTExpressionRef expression);
HTStatementRef HTStatementCreateDeclare(HTVariableRef variable, HTExpressionRef expression);
HTStatementRef HTStatementCreateIf(HTExpressionRef conditionExpression, HTListRef statementList, HTIfStatementType ifStatementType);
void HTStatementSetAsIfBranchStatement(HTStatementRef rootIfStatement, HTStatementRef branchIfStatement);
HTStatementRef HTStatementCreateFuncDef(HTExpressionRef identifier, HTListRef parameterDefList, HTListRef statementList, HTDataType returnType);
HTStatementRef HTStatementCreateReturn(HTExpressionRef returnExpr);
void HTStatementPrintDebugInfo(HTStatementRef statement);

#endif