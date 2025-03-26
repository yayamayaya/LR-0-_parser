#ifndef PARSING_TABLE_H
#define PARSING_TABLE_H

#include <unordered_map>
#include <cstddef>
#include "syntax.hpp"

#define _TDATA(row, column) parsing_table[row][column]

#define I ,

#define _TABLE_COL(col, cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8, cmd9, cmd10, cmd11, cmd12)\
_TDATA(0, col)          = cmd1; \
_TDATA(1, col)          = cmd2; \
_TDATA(2, col)          = cmd3; \
_TDATA(3, col)          = cmd4; \
_TDATA(4, col)          = cmd5; \
_TDATA(5, col)          = cmd6; \
_TDATA(6, col)          = cmd7; \
_TDATA(7, col)          = cmd8; \
_TDATA(8, col)          = cmd9; \
_TDATA(9, col)         = cmd10; \
_TDATA(10, col)         = cmd11; \
_TDATA(11, col)         = cmd12 \

enum Parser_operations
{
    SHIFT     = 0x21,
    REDUCE    = 0x22,
    GOTO      = 0x23,
    ERROR     = 0x24,

    ACCEPT    = 0x40
};

using closure_state = unsigned int;

struct operations_st
{    
    Parser_operations   op;
    closure_state       num;
};

using col_t   = std::unordered_map<Syntax_names, operations_st>;

using table_t = std::unordered_map<closure_state, col_t>;

class parse_table
{
public:

    parse_table();
    
    static inline const size_t SYNTAX_ERROR = 801;

private:
    
    static inline table_t parsing_table;

    friend class parser;
};



#endif