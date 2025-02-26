#ifndef LR_PARSER_H
#define LR_PARSER_H

#include <string>
#include <stack>
#include "parsing_table.hpp"
#include "debugging.hpp"
#include "tokenizator.hpp"

enum Parser_errors
{
    EMPTY_STRING = 1201,
};

class parser
{
public:

    ret_status parse_expression(std::string expr); 

    parser(): tokenization(), pos(0), states(), parsed_expression() {};
    
    ~parser() {};

private:

    tokenizator tokenization;

    unsigned int pos;

    std::stack<closure_state> states;

    std::stack<Syntax_names>  parsed_expression;
};

#endif