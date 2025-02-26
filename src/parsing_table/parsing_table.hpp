#ifndef PARSING_TABLE
#define PARSING_TABLE

#include <unordered_map>
#include "syntax.hpp"

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

extern std::unordered_map<closure_state, std::unordered_map<Syntax_names, operations_st>> parsing_table;

#endif