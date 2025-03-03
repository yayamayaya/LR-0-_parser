#ifndef TESTS_H
#define TESTS_H

#include "parser.hpp"

#define _TEST(test_name, expr, comment)\
void test_name();                                       \
void test_name()                                        \
{                                                       \
    parser p = {};                                      \
    ret_status status = p.parse_expression(expr);       \
                                                        \
    std::cout << comment << status << std::endl;        \
}

_TEST(empty_string_test, "", "> empty string test return status: ");

_TEST(number_test, "3", "> simple number test return status: ");

_TEST(brackets_test, "(5)", "> simple number in brackets test return status:");

_TEST(sum_test, "5 - 3", "> sum test return status: ");

_TEST(mult_test , "5 * 2", "> mult test return status: ");

_TEST(sum_mult_test, "5 + 3 * 2", "> mult and sum test return status: ");

_TEST(hard_expr_test, "(5 + 3) * (7 - 3 * 23)", "> hard expr return status: ");

#endif