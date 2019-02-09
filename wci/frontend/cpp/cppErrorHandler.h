/*
 * cppErrorHandler.h
 *
 *  Created on: Feb 6, 2019
 *      Author: willgotu
 */

#ifndef WCI_FRONTEND_CPP_CPPERRORHANDLER_H_
#define WCI_FRONTEND_CPP_CPPERRORHANDLER_H_

#include "../Token.h"
#include "../Parser.h"
#include "cppError.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;

class cppErrorHandler
{
public:
    /**
     * Getter.
     * @return the syntax error count.
     */
    int get_error_count() const;

    /**
     * Flag an error in the source line.
     * @param token the bad token.
     * @param errorCode the error code.
     * @param parser the parser.
     * @return the flagger string.
     */
    void flag(Token *token, cppErrorCode error_code, Parser *parser);

    /**
     * Abort the translation.
     * @param errorCode the error code.
     * @param parser the parser.
     */
    void abort_translation(cppErrorCode error_code, Parser *parser);

private:
    static int error_count;
    static const int MAX_ERRORS;
};

}}}  // namespace wci::frontend::cpp



#endif /* WCI_FRONTEND_CPP_CPPERRORHANDLER_H_ */
