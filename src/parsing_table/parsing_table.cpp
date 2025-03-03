#include "parsing_table.hpp"

parse_table::parse_table()
{
    _TABLE_COL(ID, 
        {SHIFT  I 5}, 
        {ERROR  I 1}, 
        {ERROR  I 1}, 
        {REDUCE I 4}, 
        {SHIFT  I 5}, 
        {REDUCE I 6}, 
        {SHIFT  I 5}, 
        {SHIFT  I 5}, 
        {ERROR  I 1}, 
        {ERROR  I 1}, 
        {REDUCE I 3}, 
        {REDUCE I 5}
    );

    _TABLE_COL(SUM,
        {ERROR  I 2},
        {SHIFT  I 6},
        {REDUCE I 2},
        {REDUCE I 4},
        {ERROR  I 2},
        {REDUCE I 6},
        {ERROR  I 2},
        {ERROR  I 2},
        {SHIFT  I 6},
        {REDUCE I 1},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(MULT,
        {ERROR  I 3},
        {ERROR  I 3},
        {SHIFT  I 7},
        {REDUCE I 4},
        {ERROR  I 3},
        {REDUCE I 6},
        {ERROR  I 3},
        {ERROR  I 3},
        {ERROR  I 3},
        {SHIFT  I 7},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(OP_BRACK,
        {SHIFT  I 4},
        {ERROR  I 4},
        {ERROR  I 4},
        {REDUCE I 4},
        {SHIFT  I 4},
        {REDUCE I 6},
        {SHIFT  I 4},
        {SHIFT  I 4},
        {ERROR  I 4},
        {ERROR  I 4},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(EXPR_END,
        {ERROR  I 5},
        {ACCEPT I 0},
        {REDUCE I 2},
        {REDUCE I 4},
        {ERROR  I 5},
        {REDUCE I 6},
        {ERROR  I 5},
        {ERROR  I 5},
        {ERROR  I 5},
        {REDUCE I 1},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(CL_BRACK,
        {ERROR  I 6},
        {ERROR  I 6},
        {REDUCE I 2},
        {REDUCE I 4},
        {ERROR  I 6},
        {REDUCE I 6},
        {ERROR  I 6},
        {ERROR  I 6},
        {SHIFT  I 11},
        {REDUCE I 1},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(E,
        {GOTO  I 1},
        {ERROR I 7},
        {ERROR I 7},
        {ERROR I 7},
        {GOTO  I 8},
        {ERROR I 7},
        {ERROR I 7},
        {ERROR I 7},
        {ERROR I 7},
        {ERROR I 7},
        {ERROR I 7},
        {ERROR I 7}
    );

    _TABLE_COL(T,
        {GOTO  I 2},
        {ERROR I 8},
        {ERROR I 8},
        {ERROR I 8},
        {GOTO  I 2},
        {ERROR I 8},
        {GOTO  I 9},
        {ERROR I 8},
        {ERROR I 8},
        {ERROR I 8},
        {ERROR I 8},
        {ERROR I 8}
    );

    _TABLE_COL(F,
        {GOTO  I 3},
        {ERROR I 9},
        {ERROR I 9},
        {ERROR I 9},
        {GOTO  I 3},
        {ERROR I 9},
        {GOTO  I 3},
        {GOTO  I 10},
        {ERROR I 9},
        {ERROR I 9},
        {ERROR I 9},
        {ERROR I 9}
    );
}
