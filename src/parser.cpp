#include "parser.hpp"
#include <iomanip>
#include <assert.h>
#include <string>

ret_status parser::parse_expression(std::string expr)
{
    _RETURN_ON_TRUE (expr.empty(), EMPTY_STRING, LOG("> the string you entered is empty\n"));

    parser_status = tokenizator::run(tkns, expr);
    _RETURN_ON_TRUE(parser_status, parser_status,);

    tokenizator::token_dump(tkns);

    LOG("> starting parsing:\n");
    
    states.push(0);

    while (1)
    {
        Syntax_names curr_tok = check_token();
        operations_st op = find_in_the_table(curr_tok);

        if (parser_status)
            return parser_status;
        
        parsing_print.print_to_table(parsed_expression, tkns.data() + pos, op);

        if      (op.op == ERROR)
            parser_status = PARSER_ERROR;
        else if (op.op == SHIFT)
            shift_operation(curr_tok, op.num);
        else if (op.op == REDUCE)
            reduce_operation(op.num);
        else if (op.op == ACCEPT)
            break;
    }
    
    LOG("> finished\n");
    
    return parser_status;
}

operations_st parser::find_in_the_table(const Syntax_names &curr_syntax)
{
    table_t::const_iterator first_iter = parsing_table.parsing_table.find(states.top());
    if (first_iter ==  parsing_table.parsing_table.end())
        return {ERROR, 101};
    
    Syntax_names syntax_mask = curr_syntax;
    if (syntax_mask & SUM)
        syntax_mask = SUM;
    if (syntax_mask & MULT)
        syntax_mask = MULT;

    col_t::const_iterator second_iter = first_iter->second.find(syntax_mask);
    if (second_iter == first_iter->second.end())
        return {ERROR, 101};

    return second_iter->second;
}

void parser::shift_operation(Syntax_names curr_tok, closure_state new_closure)
{
    parsed_expression.push(curr_tok);
    states.push(new_closure);

    pos++;
    
    return;
}

ret_status parser::assert_pop(Syntax_names name)
{
    Syntax_names curr_syntax = parsed_expression.top();
    if (name & (MULT | SUM))
    {
        if (!(name & curr_syntax))
            parser_status = PARSER_ERROR;
    }
    else if (curr_syntax != name)
        parser_status = PARSER_ERROR;
    
    parsed_expression.pop();
    states.pop();

    return parser_status;
}

void parser::reduce_operation(closure_state reduce_number)
{
    unsigned int red_num = reduce_number;

    switch (red_num)
    {
    case 1: //E -> E +|- T
        if (assert_pop(T))        return;
        if (assert_pop(SUM))      return;
        if (assert_pop(E))        return;

        parsed_expression.push(E);
        break;

    case 2: //E -> T
        if (assert_pop(T))        return;

        parsed_expression.push(E);
        break;

    case 3: //T -> T *|/ F
        if (assert_pop(F))        return;
        if (assert_pop(MULT))     return;
        if (assert_pop(T))        return;
        
        parsed_expression.push(T);
        break;

    case 4: //T -> F
        if (assert_pop(F))        return;

        parsed_expression.push(T);
        break;

    case 5: //F -> (E)
        if (assert_pop(CL_BRACK)) return;
        if (assert_pop(E))        return;
        if (assert_pop(OP_BRACK)) return;

        parsed_expression.push(F);
        break;

    case 6: //F -> ID
        if (assert_pop(ID))       return;

        parsed_expression.push(F);
        break;
    
    default:
        LOG("> fatal error happened while reduce operation");
        break;
    }

    //GOTO operation
    operations_st goto_op = find_in_the_table(parsed_expression.top());
    _RETURN_ON_TRUE(goto_op.op != GOTO,, parser_status = GOTO_ASS_ERR);

    states.push(goto_op.num);

    return;
}

Syntax_names parser::check_token()
{
    if (tkns[pos].type == NUMBER || tkns[pos].type == VAR)
        return ID;

    assert(tkns[pos].type == OPERATION);
    
    return tkns[pos].data.operation;
}