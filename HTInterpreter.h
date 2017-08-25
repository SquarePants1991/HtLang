#ifndef __HTInterpreter__H__
#define __HTInterpreter__H__

typedef enum {
    HTExpressionTypeIntLiteral,
    HTExpressionTypeDoubleLiteral,
    HTExpressionTypeBoolLiteral,
} HTExpressionType;

struct _HTExpression {
    HTExpressionType type;
    union {
        int intVal;
        double doubleVal;
    } u;
    char *stringVal;
};

typedef struct _HTExpression HTExpression;

static HTExpression HTExpressionCreateDouble(double doubleVal) {
    HTExpression expr;
    expr.type = HTExpressionTypeDoubleLiteral;
    expr.u.doubleVal = doubleVal;
    return expr;
}

static HTExpression HTExpressionAdd(HTExpression left, HTExpression right) {
    HTExpression newExpr;
    newExpr.type = HTExpressionTypeDoubleLiteral;
    newExpr.u.doubleVal = left.u.doubleVal + right.u.doubleVal;
    return newExpr;
}

static void HTExpressionPrintDesc(HTExpression expr) {
    switch (expr.type) {
        case HTExpressionTypeDoubleLiteral:
            printf("Double Literal: %lf \n", expr.u.doubleVal);
            break;
    }
}

#endif

