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


enum Syntax_names
{
    ID        = 0x01,
    SUM       = 0x60,
    MULT      = 0x70,
    OP_BRACK  = 0x04,
    CL_BRACK  = 0x05,
    EXPR_END  = 0x06,

    EP        = 0x11,
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

enum Operations
{
    PLUS        = 0x61,
    MINUS       = 0x62,
    UMNOZH      = 0x71,
    DELIT       = 0x72,

    END         = 0x81
};

#endif