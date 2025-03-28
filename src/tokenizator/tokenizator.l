%{
#include <stdio.h>

#include "tokenizator.hpp"
%}

%option noyywrap

%%
`
"+"                { return PLUS; }
"-"                { return MINUS; }
"*"                { return UMNOZH; }
"/"                { return DELIT; }
"("                { return OP_BRACK; }
")"                { return CL_BRACK; }
[0-9]+"."[0-9]*    { return ID; }
[0-9]+             { return ID; }
[A-Za-z]+[A-Za-z0-9]* { return VAR; }
[ \t\n]             
.                  {LOG("> Error: unknown symbol " << yytext[0] << std::endl); return tokenizator::LEXER_ERR;}

%%

ret_status tokenizator::run(std::vector<token_t> &tokens, const std::string expression) 
{
    yy_buffer_state *buff = yy_scan_string(expression.c_str());
    yy_switch_to_buffer(buff);

    token_t token = {};
    int tok_name = 0;

    while ((tok_name = yylex()) != 0) {
        switch(tok_name) {
            case PLUS:      
            case MINUS:     
            case UMNOZH:    
            case DELIT:     
            case OP_BRACK:  [[fallthrough]];
            case CL_BRACK:  
			{
                LOG("> OPERATION '%d' found\n" << tok_name << std::endl);

				token_data op_name = static_cast<Syntax_names>(tok_name);

				token.data = op_name;
				token.type = OPERATION;

                tokens.push_back(token);
				break;
			}

            case VAR:
            {
                LOG("> VAR ' <" << yytext << "> was found\n");

                token.var_name      = yytext;
                token.type          = VAR;

                tokens.push_back(token);
                break;
            }

            case ID: 
            {
                LOG("> NUMBER '%lf' found\n" << atof(yytext) << std::endl);

				token.data = atof(yytext);
				token.type = NUMBER;

                tokens.push_back(token);
                break;
            }

            case LEXER_ERR: [[fallthrough]];
            default: 
                LOG("> unexpected token, error\n");
                yylex_destroy();
                return LEXER_ERR;
        }
    }

    token.data = EXPR_END;
    token.type = OPERATION;

    tokens.push_back(token);

    yylex_destroy();

    return 0;
}

void tokenizator::token_dump(std::vector<token_t> tokens)
{
    LOG("> token dump start:\n");
    for (auto it = tokens.begin(); it != tokens.end(); ++it)
    {
        switch (it->type)
        {
        case NUMBER:
            LOG("> NUMBER:    <" << it->data.number << ">\n");
            break;

        case OPERATION:
            LOG("> OPERATION: <" << it->data.operation << ">\n");
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