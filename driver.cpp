#include <iostream>
#include "parser.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "> Please, enter the expression as programm parameter" << std::endl;

        return 1;
    }

    parser parsing  = {};
    ret_status ret_val = parsing.parse_expression(argv[1]);

    std::cout << "> parser finished with return status: " << ret_val << std::endl;

    return 0;
}
