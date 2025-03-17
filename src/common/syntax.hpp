#ifndef SYNTAX_HEADER
#define SYNTAX_HEADER

/*
Our parser has next syntax:

E` -> E
E  -> E +|- T   (1)
E  -> T         (2)
T  -> T *|/ F   (3)
T  -> F         (4)
F  -> (E)       (5)
F  -> ID        (6)

*/

using ret_status = int;

using number_t = double;

enum Syntax_names
{
    ID        = 0x01,

    SUM       = 0x20,
    PLUS      = 0x21,
    MINUS     = 0x22,

    MULT      = 0x40,
    UMNOZH    = 0x41,
    DELIT     = 0x42,

    OP_BRACK  = 0x04,
    CL_BRACK  = 0x05,
    
    EXPR_END  = 0x06,

    E         = 0x12,
    T         = 0x13,
    F         = 0x14
};

enum Data_types
{
    NUMBER          = 0x51,
    OPERATION       = 0x52,

    SPACE_SYMB      = 0x53,
    SYNTAX_NOT_DET  = 0x54,
};

#endif