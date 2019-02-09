/*
 * cppErrorToken.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: willgotu
 */
#include "cppErrorToken.h"
#include "../../Token.h"
#include "../cppToken.h"

namespace wci { namespace frontend { namespace cpp { namespace tokens {

using namespace std;
using namespace wci::frontend::cpp;

cppErrorToken::cppErrorToken(Source *source, cppErrorCode error_code,
                                   string token_text)
    throw (string)
    : cppToken(source)
{
    type = (TokenType) PT_ERROR;
    text = token_text;
    value = (int) error_code;
}

void cppErrorToken::extract() throw (string)
{
    // do nothing
}

}}}}  // namespace wci::frontend::cpp::tokens




