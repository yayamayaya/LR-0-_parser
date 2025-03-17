//#include "tests.hpp"

#include <gtest/gtest.h>
#include "parser.hpp"

#define _TEST(test_name, expr, expected_ret_val)                                    \
TEST(test_name, test_name)                                                          \
{                                                                                   \
    parser p = {};                                                                  \
    ret_status status = p.parse_expression(expr);                                   \
                                                                                    \
    EXPECT_EQ(status, expected_ret_val);                                            \
}

_TEST(empty_string_test, "", 1201);

_TEST(number_test, "3", 0);

_TEST(brackets_test, "(5)", 0);

_TEST(sum_test, "5 - 3", 0);

_TEST(mult_test , "5 * 2", 0);

_TEST(sum_mult_test, "5 + 3 * 2", 0);

_TEST(hard_expr_test, "(5 + 3) * (7 - 3 * 23)", 0);

_TEST(another_test, "(5 - 1 * 6) + (15 / 12)", 0);

_TEST(double_test, "5.63+ 1.25", 0);

_TEST(missing_number_test, "(5 - 1+3) * -1", 801);

_TEST(missing_bracket_test, "((5 + 1) * 2 + 5  * (3 - 1)", 801);

int main()
{
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
