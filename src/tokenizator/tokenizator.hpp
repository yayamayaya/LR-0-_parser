#ifndef TOKENIZATOR_H
#define TOKENIZATOR_H

#include "syntax.hpp"
#include <unordered_map>
#include <string>
#include <algorithm>

enum Tokenizator_error
{
    MEM_RLC_ERR         = 1011,
    NO_ARGV_STRING_ERR  = 1012,
    SYNTAX_ERR          = 1013,

    FATAL_ERR           = 404,

};

using number_t = double;

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

class tokenizator
{
public:

    ret_status run(token_t *&token_arr, const std::string expression);

private:

    inline token_t detect_token(const std::string &buff, unsigned int &pos);

    std::unordered_map<char, Syntax_names> operations =
    {
        {'+', PLUS},
        {'-', MINUS},
        {'*', UMNOZH},
        {'/', DELIT},

        {'(', OP_BRACK},
        {')', CL_BRACK}
    };

    class tokens_arr
    {
    public:

        tokens_arr(): tokens(new token_t[init_size]), array_size(init_size), token_num(0) {};
        
        ~tokens_arr () 
        {
            delete [] tokens;
        };
        
        ret_status      add_token(const token_t token);
        
        unsigned long   tokens_num() {return token_num;}
        
        token_t        *return_data();
        
        void            token_dump();
        
        private:
        
        static constexpr long int init_size = 100;
        
        token_t      *tokens;
        unsigned long array_size;
        unsigned long token_num;
        
        ret_status reallc_up()
        {
            array_size *= 2;
            token_t *arr_holder = new token_t[array_size];
            if (!arr_holder) return MEM_RLC_ERR;
            
            std::copy(tokens, tokens + token_num, arr_holder);
            
            delete [] tokens;
            
            tokens = arr_holder;
            return 0;
        }
        
        tokens_arr(const tokens_arr& copy): tokens(NULL), array_size(0), token_num(0) {(void) copy;};
        
        tokens_arr& operator=(const tokens_arr& copy)
        {
            (void) copy;
            
            return *this;
        }
    };

};  

#endif