/*
 * cppError.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: willgotu
 */
#include <string>
#include <vector>
#include <map>
#include "cppError.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;

bool cppError::INITIALIZED = false;

map<cppErrorCode, string> cppError::SYNTAX_ERROR_MESSAGES;

void cppError::initialize()
{
    if (INITIALIZED) return;

    vector<cppErrorCode> error_codes =
    {
        cppErrorCode::ALREADY_FORWARDED,
        cppErrorCode::CASE_CONSTANT_REUSED,
        cppErrorCode::IDENTIFIER_REDEFINED,
        cppErrorCode::IDENTIFIER_UNDEFINED,
        cppErrorCode::INCOMPATIBLE_ASSIGNMENT,
        cppErrorCode::INCOMPATIBLE_TYPES,
        cppErrorCode::INVALID_ASSIGNMENT,
        cppErrorCode::INVALID_CHARACTER,
        cppErrorCode::INVALID_CONSTANT,
        cppErrorCode::INVALID_EXPONENT,
        cppErrorCode::INVALID_EXPRESSION,
        cppErrorCode::INVALID_FIELD,
        cppErrorCode::INVALID_FRACTION,
        cppErrorCode::INVALID_IDENTIFIER_USAGE,
        cppErrorCode::INVALID_INDEX_TYPE,
        cppErrorCode::INVALID_NUMBER,
        cppErrorCode::INVALID_STATEMENT,
        cppErrorCode::INVALID_SUBRANGE_TYPE,
        cppErrorCode::INVALID_TARGET,
        cppErrorCode::INVALID_TYPE,
        cppErrorCode::INVALID_VAR_PARM,
        cppErrorCode::MIN_GT_MAX,
        cppErrorCode::MISSING_BEGIN,
        cppErrorCode::MISSING_COLON,
        cppErrorCode::MISSING_COLON_EQUALS,
        cppErrorCode::MISSING_COMMA,
        cppErrorCode::MISSING_CONSTANT,
        cppErrorCode::MISSING_DO,
        cppErrorCode::MISSING_DOT_DOT,
        cppErrorCode::MISSING_END,
        cppErrorCode::MISSING_EQUALS,
        cppErrorCode::MISSING_FOR_CONTROL,
        cppErrorCode::MISSING_IDENTIFIER,
        cppErrorCode::MISSING_LEFT_BRACKET,
        cppErrorCode::MISSING_OF,
        cppErrorCode::MISSING_PERIOD,
        cppErrorCode::MISSING_PROGRAM,
        cppErrorCode::MISSING_RIGHT_BRACKET,
        cppErrorCode::MISSING_RIGHT_PAREN,
        cppErrorCode::MISSING_SEMICOLON,
        cppErrorCode::MISSING_THEN,
        cppErrorCode::MISSING_TO_DOWNTO,
        cppErrorCode::MISSING_UNTIL,
        cppErrorCode::MISSING_VARIABLE,
        cppErrorCode::NOT_CONSTANT_IDENTIFIER,
        cppErrorCode::NOT_RECORD_VARIABLE,
        cppErrorCode::NOT_TYPE_IDENTIFIER,
        cppErrorCode::RANGE_INTEGER,
        cppErrorCode::RANGE_REAL,
        cppErrorCode::STACK_OVERFLOW,
        cppErrorCode::TOO_MANY_LEVELS,
        cppErrorCode::TOO_MANY_SUBSCRIPTS,
        cppErrorCode::UNEXPECTED_EOF,
        cppErrorCode::UNEXPECTED_TOKEN,
        cppErrorCode::UNIMPLEMENTED,
        cppErrorCode::UNRECOGNIZABLE,
        cppErrorCode::WRONG_NUMBER_OF_PARMS,

        // Fatal errors.
        cppErrorCode::IO_ERROR,
        cppErrorCode::TOO_MANY_ERRORS
    };

    vector<string> error_messages =
    {
        "Already specified in FORWARD",
        "CASE constant reused",
        "Redefined identifier",
        "Undefined identifier",
        "Incompatible assignment",
        "Incompatible types",
        "Invalid assignment statement",
        "Invalid character",
        "Invalid constant",
        "Invalid exponent",
        "Invalid expression",
        "Invalid field",
        "Invalid fraction",
        "Invalid identifier usage",
        "Invalid index type",
        "Invalid number",
        "Invalid statement",
        "Invalid subrange type",
        "Invalid assignment target",
        "Invalid type",
        "Invalid VAR parameter",
        "Min limit greater than max limit",
        "Missing BEGIN",
        "Missing :",
        "Missing :=",
        "Missing ,",
        "Missing constant",
        "Missing DO",
        "Missing ..",
        "Missing END",
        "Missing =",
        "Invalid FOR control variable",
        "Missing identifier",
        "Missing [",
        "Missing OF",
        "Missing .",
        "Missing PROGRAM",
        "Missing ]",
        "Missing )",
        "Missing ;",
        "Missing THEN",
        "Missing TO or DOWNTO",
        "Missing UNTIL",
        "Missing variable",
        "Not a constant identifier",
        "Not a record variable",
        "Not a type identifier",
        "Integer literal out of range",
        "Real literal out of range",
        "Stack overflow",
        "Nesting level too deep",
        "Too many subscripts",
        "Unexpected end of file",
        "Unexpected token",
        "Unimplemented feature",
        "Unrecognizable input",
        "Wrong number of actual parameters",

        // Fatal errors.
        "Object I/O error",
        "Too many syntax errors"
    };

    for (int i = 0; i < error_codes.size(); i++)
    {
        SYNTAX_ERROR_MESSAGES[error_codes[i]] = error_messages[i];
    }

    INITIALIZED = true;
}

}}}  // namespace wci::frontend::cpp



