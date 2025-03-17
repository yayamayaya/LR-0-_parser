#include "tokenizator.hpp"
#include "debugging.hpp"

#include <iostream>
#include <assert.h>
#include <string>
#include "debugging.hpp"
#include "tokenizator.hpp"

ret_status tokenizator::run(token_t *&token_arr, const std::string expression)
{
    _RETURN_ON_TRUE(!expression.c_str(), NO_ARGV_STRING_ERR, LOG("> no argument given\n"));

    LOG("> starting tokenization...\n");
    
    LOG("> initialising token array\n");
    tokens_arr tokens = {};

    LOG("> starting tokens detection\n");
    for (unsigned int pos = 0; pos < expression.size();)
    {
        token_t token = detect_token(expression, pos);
        if (token.type == SPACE_SYMB) 
            continue;

        if (token.type == SYNTAX_NOT_DET) 
            return SYNTAX_ERR;

        if (token.type != SPACE_SYMB)
        {
            _RETURN_ON_TRUE(tokens.add_token(token), MEM_RLC_ERR,);

            continue;
        }

        return FATAL_ERR;
    }

    tokens.token_dump();
    LOG("> tokenization is finished\n");

    token_arr = tokens.return_data();

    return 0;
}

inline token_t tokenizator::detect_token(const std::string &buff, unsigned int &pos)
{
    token_t token = {};

    LOG("> current pos: " << pos << ", the rest is: " << buff.data() + pos << "\n");

    if (isspace(*(buff.data() + pos)))
    {
        pos++;

        token.type = SPACE_SYMB;
        return token;
    }

    std::unordered_map<char, Syntax_names>::const_iterator iter = operations.find(*(buff.data() + pos));
    if (iter != operations.end())
    {
        LOG("> operation: '" << (unsigned int)iter->second << "' found\n");

        pos++;
        
        token.data.operation = iter->second;
        token.type = OPERATION;

        return token;
    }    
    
    int n = 0;
    number_t number = 0;
    sscanf(buff.data() + pos, "%lf%n", &number, &n);
    if (n)
    {
        LOG("> number '" << number << "' was found\n");

        pos += (unsigned int)n;

        token.data.number = number;
        token.type = NUMBER;
        return token;
    }

    LOG("> couldn't detect token, syntax error\n");
    token.type = SYNTAX_NOT_DET;
    return token;
}

