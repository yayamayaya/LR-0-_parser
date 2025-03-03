#include "parsing_print.hpp"
#include <iomanip>
#include <assert.h>

using std::setw;

parsing_printer::parsing_printer()
{
    std::cout << setw(15) << "STACK" << setw(10) << "|" \
        << setw(15) << "INPUT" << setw(10) << "|" \
            << setw(15) <<  "ACTION" << std::endl;
}

void parsing_printer::print_to_table(const std::stack<Syntax_names> &st, const token_t *tokens, operations_st op)
{
    //For accurate table
    std::string stack_str   = print_stack(st);

    std::cout << setw(5) << "" << stack_str << setw((int)(20 - stack_str.length())) << "|" \
        << setw(20) << print_input(tokens) << setw(5) << "|" \
            << setw(5) << "" << print_action(op) << std::endl;
}

std::string parsing_printer::print_action(operations_st op)
{
    std::string action = {};

    if (op.op == REDUCE)
    {
        reduce_output::iterator iter = reduce_print.find(op.num);
        if (iter != reduce_print.end())
            action = "Reduce " + iter->second;
    }
    if (op.op == SHIFT)
    {
        action = "Shift";
    }
    if (op.op == ACCEPT)
    {
        action = "Accept";
    }

    return action;
}

std::string parsing_printer::print_stack(std::stack<Syntax_names> st)
{
    if (st.empty())
        return "$";

    Syntax_names stack_data = st.top();
    st.pop();

    std::stringstream stack_str = {};
    
    stack_str << print_stack(st);

    output_table::iterator iter = syntax_output.find(stack_data);
    if (iter != syntax_output.end())
        stack_str << iter->second;

    return stack_str.str();
}

std::string parsing_printer::print_input(const token_t *tokens)
{
    assert(tokens);

    if (tokens->type == OPERATION && tokens->data.operation == EXPR_END)
        return "$";
    
    std::stringstream input_str = {};

    if (tokens->type == NUMBER)
        input_str << std::setprecision(2) << tokens->data.number;
    if (tokens->type == OPERATION)
    {
        output_table::iterator iter = syntax_output.find(tokens->data.operation);
        if (iter != syntax_output.end())
            input_str << iter->second;
    }

    input_str << print_input(tokens + 1);

    return input_str.str();
}