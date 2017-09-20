//
// Created by wang yang on 2017/9/20.
//

#ifndef HTLANG_HTLANG_CTRL_H
#define HTLANG_HTLANG_CTRL_H

typedef enum {
    HTUnitTestLevelError = 0,
    HTUnitTestLevelSuccess = 1,
    HTUnitTestLevelVerbose = 2,
} HTUnitTestLevel;

extern HTUnitTestLevel CTRL_UnitTestLevel;

#endif //HTLANG_HTLANG_CTRL_H
