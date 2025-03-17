#ifndef LR_PARSER_H
#define LR_PARSER_H

#include <string>
#include <stack>
#include "parsing_table.hpp"
#include "debugging.hpp"
#include "tokenizator.hpp"
#include "parsing_print.hpp"

class parser
{
public:

    enum Parser_errors
    {
        EMPTY_STRING = 1201,
        PARSER_ERROR = 1202,
        GOTO_ASS_ERR = 1203,
    };

    ret_status parse_expression(std::string expr); 

    parser(): tkns(), pos(0), parser_status(), states(), parsed_expression() {};
    
    ~parser() {};

private:

    std::vector<tokenizator::token_t> tkns;

    unsigned int pos;

    ret_status   parser_status;

    std::stack<closure_state> states;

    std::stack<Syntax_names>  parsed_expression;

    parse_table     parsing_table;

    parsing_printer parsing_print;

    operations_st find_in_the_table(const Syntax_names &curr_syntax);

    void shift_operation(Syntax_names curr_tok, closure_state new_closure);

    ret_status assert_pop(Syntax_names name);

    void reduce_operation(closure_state reduce_number);

    Syntax_names check_token();

    const parser &operator=(const parser &cp) =delete;

    parser(const parser &cp) =delete;
};

#endif