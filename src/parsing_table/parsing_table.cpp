#include "parsing_table.hpp"

parse_table::parse_table()
{
    _TABLE_COL(ID, 
        {SHIFT  I 5}, 
        {ERROR  I SYNTAX_ERROR}, 
        {ERROR  I SYNTAX_ERROR}, 
        {REDUCE I 4}, 
        {SHIFT  I 5}, 
        {REDUCE I 6}, 
        {SHIFT  I 5}, 
        {SHIFT  I 5}, 
        {ERROR  I SYNTAX_ERROR}, 
        {ERROR  I SYNTAX_ERROR}, 
        {REDUCE I 3}, 
        {REDUCE I 5}
    );

    _TABLE_COL(SUM,
        {ERROR  I SYNTAX_ERROR},
        {SHIFT  I 6},
        {REDUCE I 2},
        {REDUCE I 4},
        {ERROR  I SYNTAX_ERROR},
        {REDUCE I 6},
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {SHIFT  I 6},
        {REDUCE I 1},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(MULT,
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {SHIFT  I 7},
        {REDUCE I 4},
        {ERROR  I SYNTAX_ERROR},
        {REDUCE I 6},
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {SHIFT  I 7},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(OP_BRACK,
        {SHIFT  I 4},
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {REDUCE I 4},
        {SHIFT  I 4},
        {REDUCE I 6},
        {SHIFT  I 4},
        {SHIFT  I 4},
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(EXPR_END,
        {ERROR  I SYNTAX_ERROR},
        {ACCEPT I 0},
        {REDUCE I 2},
        {REDUCE I 4},
        {ERROR  I SYNTAX_ERROR},
        {REDUCE I 6},
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {REDUCE I 1},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(CL_BRACK,
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {REDUCE I 2},
        {REDUCE I 4},
        {ERROR  I SYNTAX_ERROR},
        {REDUCE I 6},
        {ERROR  I SYNTAX_ERROR},
        {ERROR  I SYNTAX_ERROR},
        {SHIFT  I 11},
        {REDUCE I 1},
        {REDUCE I 3},
        {REDUCE I 5}
    );

    _TABLE_COL(E,
        {GOTO  I 1},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {GOTO  I 8},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR}
    );

    _TABLE_COL(T,
        {GOTO  I 2},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {GOTO  I 2},
        {ERROR I SYNTAX_ERROR},
        {GOTO  I 9},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR}
    );

    _TABLE_COL(F,
        {GOTO  I 3},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {GOTO  I 3},
        {ERROR I SYNTAX_ERROR},
        {GOTO  I 3},
        {GOTO  I 10},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR},
        {ERROR I SYNTAX_ERROR}
    );
}
