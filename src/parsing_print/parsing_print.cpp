#include "parsing_print.hpp"
#include <iomanip>
#include <assert.h>

using std::setw;

parsing_printer::parsing_printer()
{
    std::cout << setw(INDENT_FIFT) << "STACK" << setw(INDENT_TEN) << "|" \
        << setw(INDENT_FIFT) << "INPUT" << setw(INDENT_TEN) << "|" \
            << setw(INDENT_FIFT) <<  "ACTION" << std::endl;
}

void parsing_printer::print_to_table(const std::stack<Syntax_names> &st, const tokenizator::token_t *tokens, operations_st op)
{
    //For accurate table
    std::string stack_str   = print_stack(st);

    std::cout << setw(INDENT_FIVE) << "" << stack_str << setw((int)(INDENT_TWEN - stack_str.length())) << "|" \
        << setw(INDENT_TWEN) << print_input(tokens) << setw(INDENT_FIVE) << "|" \
            << setw(INDENT_FIVE) << "" << print_action(op) << std::endl;
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
        action = "Shift";
    if (op.op == ACCEPT)
        action = "Accept";
    if (op.op == ERROR)
        action = "Error";

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

std::string parsing_printer::print_input(const tokenizator::token_t *tokens)
{
    assert(tokens);

    if (tokens->type == OPERATION && tokens->data.operation == EXPR_END)
        return "$";
    
    std::stringstream input_str = {};

    if (tokens->type == NUMBER)
    {
        int precision = 0;

        if (tokens->data.number != static_cast<int>(tokens->data.number))
            precision = 2;
        
        input_str << std::setprecision(precision) << std::fixed << tokens->data.number;
    }
    if (tokens->type == OPERATION)
    {
        output_table::iterator iter = syntax_output.find(tokens->data.operation);
        if (iter != syntax_output.end())
            input_str << iter->second;
    }

    input_str << print_input(tokens + 1);

    return input_str.str();
}