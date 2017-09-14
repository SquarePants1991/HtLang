//
// Created by wang yang on 2017/9/14.
//

#ifndef HTLANG_HTEXPRESSIONFORCECONVERT_H
#define HTLANG_HTEXPRESSIONFORCECONVERT_H

#include "../compiler/HTExpression.h"

HTVariableRef HTVariableConvertToDouble(HTVariableRef variable, unsigned char useOriginVariable);
HTVariableRef HTVariableConvertToInt(HTVariableRef variable, unsigned char useOriginVariable);
HTVariableRef HTVariableConvertToString(HTVariableRef variable, unsigned char useOriginVariable);
HTVariableRef HTVariableConvertToBool(HTVariableRef variable, unsigned char useOriginVariable);

#endif //HTLANG_HTEXPRESSIONFORCECONVERT_H
