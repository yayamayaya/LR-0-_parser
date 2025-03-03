#ifndef PRINT_PARSING_H
#define PRINT_PARSING_H

#include "syntax.hpp"
#include "tokenizator.hpp"
#include "debugging.hpp"
#include "parsing_table.hpp"
#include <stack>
#include <unordered_map>
#include <string>

using output_table = std::unordered_map<Syntax_names, std::string>;

using reduce_output = std::unordered_map<closure_state, std::string>;

class parsing_printer
{
private:
    static inline output_table syntax_output =
    {
        {ID,       "id" },
        {SUM,      "+|-"},
        {PLUS,     "+"  },
        {MINUS,    "-"  },
        {MULT,     "*|/"},
        {UMNOZH,   "*"  },
        {DELIT,    "/"  },
        {OP_BRACK, "("  },
        {CL_BRACK, ")"  },
        {EXPR_END, "$"  },
        {E,        "E"  },
        {T,        "T"  },
        {F,        "F"  },
    };

    static inline reduce_output reduce_print = 
    {
        {1, "E -> E +|- T"},
        {2, "E -> T"},
        {3, "T -> T *|/ F"},
        {4, "T -> F"},
        {5, "F -> (E)"},
        {6, "F -> id"},
    };
    
    std::string print_stack(std::stack<Syntax_names> st);

    std::string print_input(const token_t *tokens);

    std::string print_action(operations_st op);

public:

    parsing_printer();

    void print_to_table(const std::stack<Syntax_names> &st, const token_t *tokens, operations_st op);
};


#endif