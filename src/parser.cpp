#include "parser.hpp"

ret_status parser::parse_expression(std::string expr)
{
    _RETURN_ON_TRUE (expr.empty(), EMPTY_STRING, LOG("> the string you entered is empty\n"));

    token_t *tokens_arr = nullptr;

    ret_status status = tokenization.run(tokens_arr, expr);
    _RETURN_ON_TRUE(status, status);

    delete [] tokens_arr;

    return status;
}