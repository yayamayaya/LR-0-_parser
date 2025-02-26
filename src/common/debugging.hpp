#ifndef DEBIGGING_H
#define DEBUGGING_H

#include <iostream>

using ret_status = int;

#define LOG(arg) std::cout << arg

#define _RETURN_ON_TRUE(statement, ret_val, ...)            \
    do                                                      \
    {                                                       \
        if (statement)                                      \
        {                                                   \
            __VA_ARGS__;                                    \
            return ret_val;                                 \
        }                                                   \
    } while (0)

#endif