#ifndef __HTExpressionEval_H_
#define __HTExpressionEval_H_

#include <compiler/HTExpression.h>
#include <compiler/HTVariable.h>
#include "../compiler/HTExpression.h"
#include <math.h>
#include "HTRuntimeEnvironment.h"

HTVariableRef HTExpressionEvaluate(HTExpressionRef expr, HTRuntimeEnvironmentRef rootEnv);
void HTExpressionConvertToDouble(HTExpressionRef expression);
void HTExpressionConvertToInt(HTExpressionRef expression);
void HTExpressionConvertToString(HTExpressionRef expression);
/** 隐式转换规则。
 * 1. 有一个是字符串，则结果为字符串
 * 2. 有一个是double，则结果为double
 * 3. 否则结果为int
 */
HTVariableRef HTExpressionEvaluateBinaryOperation(HTExpressionRef expr, HTRuntimeEnvironmentRef rootEnv);

#endif