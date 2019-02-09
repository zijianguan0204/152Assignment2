/*
 * cppScanner.h
 *
 *  Created on: Feb 6, 2019
 *      Author: willgotu
 */

#ifndef WCI_FRONTEND_CPP_CPPSCANNER_H_
#define WCI_FRONTEND_CPP_CPPSCANNER_H_

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;

class cppScanner : public Scanner
{
public:
    /**
     * Constructor
     * @param source the source to be used with this scanner.
     */
    cppScanner(Source *source);

protected:
    /**
     * Extract and return the next cpp token from the source.
     * @return the next token.
     * @throw a string message if an error occurred.
     */
    Token *extract_token() throw (string);

private:
    /**
     * Skip whitespace characters by consuming them.  A comment is whitespace.
     * @throw a string message if an error occurred.
     */
    void skip_white_space() throw (string);
};

}}} // namespace wci::frontend::cpp

#endif /* WCI_FRONTEND_CPP_CPPSCANNER_H_ */



