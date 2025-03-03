#include "tests.hpp"

int main()
{
    std::cout << "running tests\n";
    empty_string_test();
    number_test();
    brackets_test();
    sum_test();
    mult_test();
    sum_mult_test();
    hard_expr_test();
    std::cout << "tests finished\n";

    return 0;
}
