#ifndef RULES_H
#define RULES_H

#include "Lenta.h"

class Rules {

public:
    Rules(){}
    bool move(int startRow, int startCol, int endRow, int endCol, const Lenta& lenta);
    bool capture(int startRow, int startCol, int endRow, int endCol, const Lenta& lenta);
    void promote(int row, int col, Lenta& lenta);
};

#endif // RULES_H
