#ifndef TOKENIZATOR_H
#define TOKENIZATOR_H

#include "syntax.hpp"
#include "debugging.hpp"
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

namespace tokenizator
{
    static inline const ret_status LEXER_ERR = 1013;

    union token_data
    {
        token_data() {};
        
        token_data(number_t num):    number(num) {};
        
        token_data(Syntax_names op): operation(op) {}; 
        
        ~token_data() {};
        
        number_t number;
        
        Syntax_names operation;
    };
    
    struct token_t
    {
        token_t(): data(), type() {};
        ~token_t() {};
        
        token_data data;
        Data_types type;
    };

    ret_status run(std::vector<token_t> &token_arr, const std::string expression);

    void token_dump(std::vector<token_t> tokens);
};  

#endif