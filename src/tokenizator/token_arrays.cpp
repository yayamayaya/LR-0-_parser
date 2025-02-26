#include <iostream>
#include "tokenizator.hpp"
#include "debugging.hpp"

token_t *tokenizator::tokens_arr::return_data() 
{
    token_t *returning_data = new token_t[token_num + 1];
    if (!returning_data) return NULL;

    std::copy(tokens, tokens + token_num, returning_data);

    token_t last_token = {};
    last_token.data = END;
    last_token.type = OPERATION;

    *(returning_data + token_num) = last_token;

    return returning_data;
}

ret_status tokenizator::tokens_arr::add_token(const token_t token)
{
    if (token_num == array_size)
        if (reallc_up())
            return MEM_RLC_ERR;

    tokens[token_num] = token;
    token_num++;

    return 0;
}

void tokenizator::tokens_arr::token_dump()
{
    LOG("> token dump start:\n");
    for (unsigned long pos = 0; pos < token_num; pos++)
    {
        switch (tokens[pos].type)
        {
        case NUMBER:
            LOG("> NUMBER:    <" << tokens[pos].data.number << ">\n");
            break;

        case OPERATION:
            LOG("> OPERATION: <" << (unsigned int)tokens[pos].data.operation << ">\n");
            break;

        case SPACE_SYMB:
        case SYNTAX_NOT_DET:
            [[fallthrough]];

        default:
            LOG("> fatal error\n");
            break;
        }
    }

    LOG("> token dump ended.\n");
    return;
}