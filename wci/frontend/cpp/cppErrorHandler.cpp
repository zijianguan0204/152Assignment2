/*
 * cppErrorHandler.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: willgotu
 */

#include "cppErrorHandler.h"
#include "../Token.h"
#include "../Parser.h"
#include "cppError.h"
#include "../../message/Message.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;

const int cppErrorHandler::MAX_ERRORS = 25;
int cppErrorHandler::error_count = 0;

int cppErrorHandler::get_error_count() const { return error_count; }

void cppErrorHandler::flag(Token *token, cppErrorCode error_code,
                              Parser *parser)
{
    // Notify the parser's listeners.
    string error_message = cppError::SYNTAX_ERROR_MESSAGES[error_code];
    Message message(SYNTAX_ERROR,
                    LINE_NUMBER, to_string(token->get_line_number()),
                    POSITION, to_string(token->get_position()),
                    TOKEN_TEXT, token->get_text(),
                    ERROR_MESSAGE, error_message);
    parser->send_message(message);

    if (++error_count > MAX_ERRORS)
    {
        abort_translation(TOO_MANY_ERRORS, parser);
    }
}

void cppErrorHandler::abort_translation(cppErrorCode error_code,
                                           Parser *parser)
{
    // Notify the parser's listeners and then abort.
    string error_message = "FATAL ERROR: " +
                           cppError::SYNTAX_ERROR_MESSAGES[error_code];
    Message message(SYNTAX_ERROR,
                    LINE_NUMBER, "0",
                    POSITION, "0",
                    TOKEN_TEXT, "",
                    ERROR_MESSAGE, error_message);
    parser->send_message(message);
    exit(-2);
}

}}}  // namespace wci::frontend::cpp



