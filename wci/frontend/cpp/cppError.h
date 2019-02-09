/*
 * cppError.h
 *
 *  Created on: Feb 6, 2019
 *      Author: willgotu
 */

#ifndef WCI_FRONTEND_CPP_CPPERROR_H_
#define WCI_FRONTEND_CPP_CPPERROR_H_

#include <string>
#include <map>

namespace wci { namespace frontend { namespace cpp {

using namespace std;

/**
 * cpp error codes.
 */
enum class cppErrorCode
{
    ALREADY_FORWARDED,
    CASE_CONSTANT_REUSED,
    IDENTIFIER_REDEFINED,
    IDENTIFIER_UNDEFINED,
    INCOMPATIBLE_ASSIGNMENT,
    INCOMPATIBLE_TYPES,
    INVALID_ASSIGNMENT,
    INVALID_CHARACTER,
    INVALID_CONSTANT,
    INVALID_EXPONENT,
    INVALID_EXPRESSION,
    INVALID_FIELD,
    INVALID_FRACTION,
    INVALID_IDENTIFIER_USAGE,
    INVALID_INDEX_TYPE,
    INVALID_NUMBER,
    INVALID_STATEMENT,
    INVALID_SUBRANGE_TYPE,
    INVALID_TARGET,
    INVALID_TYPE,
    INVALID_VAR_PARM,
    MIN_GT_MAX,
    MISSING_BEGIN, // { in c++
    MISSING_COLON, // : in c++
    MISSING_COLON_EQUALS,
    MISSING_COMMA, // , in c++
    MISSING_CONSTANT,
    MISSING_DO,
    MISSING_DOT_DOT,
    MISSING_END, // } in c++
    MISSING_EQUALS, // = in c++
    MISSING_FOR_CONTROL,
    MISSING_IDENTIFIER,
    MISSING_LEFT_BRACKET,
    MISSING_OF,
    MISSING_PERIOD,
    MISSING_PROGRAM,
    MISSING_RIGHT_BRACKET,
    MISSING_RIGHT_PAREN, // ) in c++
    MISSING_SEMICOLON, //; in c++
    MISSING_THEN,
    MISSING_TO_DOWNTO,
    MISSING_UNTIL,
    MISSING_VARIABLE,
    NOT_CONSTANT_IDENTIFIER,
    NOT_RECORD_VARIABLE,
    NOT_TYPE_IDENTIFIER,
    RANGE_INTEGER,
    RANGE_REAL,
    STACK_OVERFLOW,
    TOO_MANY_LEVELS,
    TOO_MANY_SUBSCRIPTS,
    UNEXPECTED_EOF,
    UNEXPECTED_TOKEN,
    UNIMPLEMENTED,
    UNRECOGNIZABLE,
    WRONG_NUMBER_OF_PARMS,

    // Fatal errors.
    IO_ERROR,
    TOO_MANY_ERRORS
};

constexpr cppErrorCode ALREADY_FORWARDED = cppErrorCode::ALREADY_FORWARDED;
constexpr cppErrorCode CASE_CONSTANT_REUSED = cppErrorCode::CASE_CONSTANT_REUSED;
constexpr cppErrorCode IDENTIFIER_REDEFINED = cppErrorCode::IDENTIFIER_REDEFINED;
constexpr cppErrorCode IDENTIFIER_UNDEFINED = cppErrorCode::IDENTIFIER_UNDEFINED;
constexpr cppErrorCode INCOMPATIBLE_ASSIGNMENT = cppErrorCode::INCOMPATIBLE_ASSIGNMENT;
constexpr cppErrorCode INCOMPATIBLE_TYPES = cppErrorCode::INCOMPATIBLE_TYPES;
constexpr cppErrorCode INVALID_ASSIGNMENT = cppErrorCode::INVALID_ASSIGNMENT;
constexpr cppErrorCode INVALID_CHARACTER = cppErrorCode::INVALID_CHARACTER;
constexpr cppErrorCode INVALID_CONSTANT = cppErrorCode::INVALID_CONSTANT;
constexpr cppErrorCode INVALID_EXPONENT = cppErrorCode::INVALID_EXPONENT;
constexpr cppErrorCode INVALID_EXPRESSION = cppErrorCode::INVALID_EXPRESSION;
constexpr cppErrorCode INVALID_FIELD = cppErrorCode::INVALID_FIELD;
constexpr cppErrorCode INVALID_FRACTION = cppErrorCode::INVALID_FRACTION;
constexpr cppErrorCode INVALID_IDENTIFIER_USAGE = cppErrorCode::INVALID_IDENTIFIER_USAGE;
constexpr cppErrorCode INVALID_INDEX_TYPE = cppErrorCode::INVALID_INDEX_TYPE;
constexpr cppErrorCode INVALID_NUMBER = cppErrorCode::INVALID_NUMBER;
constexpr cppErrorCode INVALID_STATEMENT = cppErrorCode::INVALID_STATEMENT;
constexpr cppErrorCode INVALID_SUBRANGE_TYPE = cppErrorCode::INVALID_SUBRANGE_TYPE;
constexpr cppErrorCode INVALID_TARGET = cppErrorCode::INVALID_TARGET;
constexpr cppErrorCode INVALID_TYPE = cppErrorCode::INVALID_TYPE;
constexpr cppErrorCode INVALID_VAR_PARM = cppErrorCode::INVALID_VAR_PARM;
constexpr cppErrorCode MIN_GT_MAX = cppErrorCode::MIN_GT_MAX;
constexpr cppErrorCode MISSING_BEGIN = cppErrorCode::MISSING_BEGIN;
constexpr cppErrorCode MISSING_COLON = cppErrorCode::MISSING_COLON;
constexpr cppErrorCode MISSING_COMMA = cppErrorCode::MISSING_COMMA;
constexpr cppErrorCode MISSING_CONSTANT = cppErrorCode::MISSING_CONSTANT;
constexpr cppErrorCode MISSING_DO = cppErrorCode::MISSING_DO;
constexpr cppErrorCode MISSING_DOT_DOT = cppErrorCode::MISSING_DOT_DOT;
constexpr cppErrorCode MISSING_END = cppErrorCode::MISSING_END;
constexpr cppErrorCode MISSING_EQUALS = cppErrorCode::MISSING_EQUALS;
constexpr cppErrorCode MISSING_COLON_EQUALS = cppErrorCode::MISSING_COLON_EQUALS;
constexpr cppErrorCode MISSING_FOR_CONTROL = cppErrorCode::MISSING_FOR_CONTROL;
constexpr cppErrorCode MISSING_IDENTIFIER = cppErrorCode::MISSING_IDENTIFIER;
constexpr cppErrorCode MISSING_LEFT_BRACKET = cppErrorCode::MISSING_LEFT_BRACKET;
constexpr cppErrorCode MISSING_OF = cppErrorCode::MISSING_OF;
constexpr cppErrorCode MISSING_PERIOD = cppErrorCode::MISSING_PERIOD;
constexpr cppErrorCode MISSING_PROGRAM = cppErrorCode::MISSING_PROGRAM;
constexpr cppErrorCode MISSING_RIGHT_BRACKET = cppErrorCode::MISSING_RIGHT_BRACKET;
constexpr cppErrorCode MISSING_RIGHT_PAREN = cppErrorCode::MISSING_RIGHT_PAREN;
constexpr cppErrorCode MISSING_SEMICOLON = cppErrorCode::MISSING_SEMICOLON;
constexpr cppErrorCode MISSING_THEN = cppErrorCode::MISSING_THEN;
constexpr cppErrorCode MISSING_TO_DOWNTO = cppErrorCode::MISSING_TO_DOWNTO;
constexpr cppErrorCode MISSING_UNTIL = cppErrorCode::MISSING_UNTIL;
constexpr cppErrorCode MISSING_VARIABLE = cppErrorCode::MISSING_VARIABLE;
constexpr cppErrorCode NOT_CONSTANT_IDENTIFIER = cppErrorCode::NOT_CONSTANT_IDENTIFIER;
constexpr cppErrorCode NOT_RECORD_VARIABLE = cppErrorCode::NOT_RECORD_VARIABLE;
constexpr cppErrorCode NOT_TYPE_IDENTIFIER = cppErrorCode::NOT_TYPE_IDENTIFIER;
constexpr cppErrorCode RANGE_INTEGER = cppErrorCode::RANGE_INTEGER;
constexpr cppErrorCode RANGE_REAL = cppErrorCode::RANGE_REAL;
constexpr cppErrorCode STACK_OVERFLOW = cppErrorCode::STACK_OVERFLOW;
constexpr cppErrorCode TOO_MANY_LEVELS = cppErrorCode::TOO_MANY_LEVELS;
constexpr cppErrorCode TOO_MANY_SUBSCRIPTS = cppErrorCode::TOO_MANY_SUBSCRIPTS;
constexpr cppErrorCode UNEXPECTED_EOF = cppErrorCode::UNEXPECTED_EOF;
constexpr cppErrorCode UNEXPECTED_TOKEN = cppErrorCode::UNEXPECTED_TOKEN;
constexpr cppErrorCode UNIMPLEMENTED = cppErrorCode::UNIMPLEMENTED;
constexpr cppErrorCode UNRECOGNIZABLE = cppErrorCode::UNRECOGNIZABLE;
constexpr cppErrorCode WRONG_NUMBER_OF_PARMS = cppErrorCode::WRONG_NUMBER_OF_PARMS;

constexpr cppErrorCode IO_ERROR = cppErrorCode::IO_ERROR;
constexpr cppErrorCode TOO_MANY_ERRORS = cppErrorCode::TOO_MANY_ERRORS;

class cppError
{
public:
    static map<cppErrorCode, string> SYNTAX_ERROR_MESSAGES;

    /**
     * Initialize the static map.
     */
    static void initialize();

private:
    static bool INITIALIZED;
};

}}}  // namespace wci::frontend::cpp



#endif /* WCI_FRONTEND_CPP_CPPERROR_H_ */
