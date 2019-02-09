/*
 * cppScanner.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: willgotu
 */

#include <iostream>
#include "cppScanner.h"
#include "cppToken.h"
#include "cppError.h"
#include "../Source.h"
#include "tokens/cppWordToken.h"
#include "tokens/cppNumberToken.h"
#include "tokens/cppStringToken.h"
#include "tokens/cppSpecialSymbolToken.h"
#include "tokens/cppErrorToken.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::cpp::tokens;

cppScanner::cppScanner(Source *source) : Scanner(source)
{
}

Token *cppScanner::extract_token() throw (string)
{
    skip_white_space();

    Token *token;
    char current_ch = current_char();
    string string_ch = " ";

    string_ch[0] = current_ch;

    // Construct the next token.  The current character determines the
    // token type.
    if (current_ch == Source::END_OF_FILE)
    {
        token = nullptr;
    }
    else if (isalpha(current_ch))
    {
        token = new cppWordToken(source);
    }
    else if (isdigit(current_ch))
    {
        token = new cppNumberToken(source);
    }
    else if (current_ch == '\'')
    {
        token = new cppStringToken(source);
    }
    else if (cppToken::SPECIAL_SYMBOLS.find(string_ch)
                != cppToken::SPECIAL_SYMBOLS.end())
    {
        token = new cppSpecialSymbolToken(source);
    }
    else
    {
        token = new cppErrorToken(source, INVALID_CHARACTER, string_ch);
        next_char();  // consume character
    }

    return token;
}

void cppScanner::skip_white_space() throw (string)
{
    char current_ch = current_char();

    while (isspace(current_ch) || (current_ch == '{')) {

        // Start of a comment?
        if (current_ch == '{')
        {
            do
            {
                current_ch = next_char();  // consume comment characters
            } while ((current_ch != '}') &&
                     (current_ch != Source::END_OF_FILE));

            // Found closing '}'?
            if (current_ch == '}')
            {
                current_ch = next_char();  // consume the '}'
            }
        }

        // Not a comment.
        else current_ch = next_char();  // consume whitespace character
    }
}

}}} // namespace wci::frontend::cpp
