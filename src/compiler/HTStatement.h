#ifndef __HTStatement_H__
#define __HTStatement_H__

#include "HTExpression.h"

enum HTStatementType {
	HTStatementTypePureExpression,
	HTStatementTypeAssign,
	HTStatementTypeDeclare,
	HTStatementTypeIf,
	HTStatementTypeFor,
    HTStatementTypeWhile,
	HTStatementTypeFuncDef,
    HTStatementTypeReturn,
    HTStatementTypeBreak,
    HTStatementTypeContinue,
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
	HTExpressionRef identifierExpression;
    HTExpressionRef arrayExpression;
    HTListRef statementList;
} HTStatementFor;

typedef struct {
    HTExpressionRef conditionExpression;
    HTListRef statementList;
} HTStatementWhile;


HTClassBegin
	enum HTStatementType type;
	union {
		HTStatementPureExpression pureExpressionStatement;
		HTStatementAssign assignStatement;
		HTStatementDeclare declareStatement;
		HTStatementIf ifStatement;
		HTStatementFuncDef funcDefStatement;
        HTStatementReturn returnStatement;
        HTStatementFor forStatement;
        HTStatementWhile whileStatement;
	} u;
HTClassEnd(HTStatement)

HTStatementRef HTStatementCreatePureExpression(HTExpressionRef expression);
HTStatementRef HTStatementCreateAssign(HTExpressionRef identifier, HTExpressionRef expression);
HTStatementRef HTStatementCreateDeclare(HTVariableRef variable, HTExpressionRef expression);
HTStatementRef HTStatementCreateIf(HTExpressionRef conditionExpression, HTListRef statementList, HTIfStatementType ifStatementType);
void HTStatementSetAsIfBranchStatement(HTStatementRef rootIfStatement, HTStatementRef branchIfStatement);
HTStatementRef HTStatementCreateFuncDef(HTExpressionRef identifier, HTListRef parameterDefList, HTListRef statementList, HTDataType returnType);
HTStatementRef HTStatementCreateReturn(HTExpressionRef returnExpr);
HTStatementRef HTStatementCreateFor(HTExpressionRef identifier, HTExpressionRef arrayExpression, HTListRef statementList);
HTStatementRef HTStatementCreateWhile(HTExpressionRef conditionExpression, HTListRef statementList);
HTStatementRef HTStatementCreateBreak();
HTStatementRef HTStatementCreateContinue();
void HTStatementPrintDebugInfo(HTStatementRef statement);

#endif