/*
 * cppToken.h
 *
 *  Created on: Feb 6, 2019
 *      Author: willgotu
 */

#ifndef WCI_FRONTEND_CPP_CPPTOKEN_H_
#define WCI_FRONTEND_CPP_CPPTOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;
using namespace wci::frontend;

/**
 * cpp token types.
 */
enum class cppTokenType
{
    // Reserved words.
    AND, ARRAY, BEGIN, CASE, CONST, DIV, DO, DOWNTO, ELSE, END,
    FILE, FOR, FUNCTION, GOTO, IF, IN, LABEL, MOD, NIL, NOT,
    OF, OR, PACKED, PROCEDURE, PROGRAM, RECORD, REPEAT, SET,
    THEN, TO, TYPE, UNTIL, VAR, WHILE, WITH,

    // Special symbols.
    PLUS, MINUS, STAR, SLASH, COLON_EQUALS,
    DOT, COMMA, SEMICOLON, COLON, QUOTE,
    EQUALS, NOT_EQUALS, LESS_THAN, LESS_EQUALS,
    GREATER_EQUALS, GREATER_THAN, LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
    UP_ARROW, DOT_DOT,

    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

constexpr cppTokenType PT_AND = cppTokenType::AND;
constexpr cppTokenType PT_ARRAY = cppTokenType::ARRAY;
constexpr cppTokenType PT_BEGIN = cppTokenType::BEGIN;
constexpr cppTokenType PT_CASE = cppTokenType::CASE;
constexpr cppTokenType PT_CONST = cppTokenType::CONST;
constexpr cppTokenType PT_DIV = cppTokenType::DIV;
constexpr cppTokenType PT_DO = cppTokenType::DO;
constexpr cppTokenType PT_DOWNTO = cppTokenType::DOWNTO;

constexpr cppTokenType PT_ELSE = cppTokenType::ELSE;
constexpr cppTokenType PT_END = cppTokenType::END;
constexpr cppTokenType PT_FILE = cppTokenType::FILE;
constexpr cppTokenType PT_FOR = cppTokenType::FOR;
constexpr cppTokenType PT_FUNCTION = cppTokenType::FUNCTION;
constexpr cppTokenType PT_GOTO = cppTokenType::GOTO;
constexpr cppTokenType PT_IF = cppTokenType::IF;
constexpr cppTokenType PT_IN = cppTokenType::IN;

constexpr cppTokenType PT_LABEL = cppTokenType::LABEL;
constexpr cppTokenType PT_MOD = cppTokenType::MOD;
constexpr cppTokenType PT_NIL = cppTokenType::NIL;
constexpr cppTokenType PT_NOT = cppTokenType::NOT;
constexpr cppTokenType PT_OF = cppTokenType::OF;
constexpr cppTokenType PT_OR = cppTokenType::OR;
constexpr cppTokenType PT_PACKED = cppTokenType::PACKED;
constexpr cppTokenType PT_PROCEDURE = cppTokenType::PROCEDURE;

constexpr cppTokenType PT_PROGRAM = cppTokenType::PROGRAM;
constexpr cppTokenType PT_RECORD = cppTokenType::RECORD;
constexpr cppTokenType PT_REPEAT = cppTokenType::REPEAT;
constexpr cppTokenType PT_SET = cppTokenType::SET;
constexpr cppTokenType PT_THEN = cppTokenType::THEN;
constexpr cppTokenType PT_TO = cppTokenType::TO;
constexpr cppTokenType PT_TYPE = cppTokenType::TYPE;

constexpr PascalTokenType PT_UNTIL = PascalTokenType::UNTIL;
constexpr PascalTokenType PT_VAR = PascalTokenType::VAR;
constexpr PascalTokenType PT_WHILE = PascalTokenType::WHILE;
constexpr PascalTokenType PT_WITH = PascalTokenType::WITH;

constexpr PascalTokenType PT_PLUS = PascalTokenType::PLUS;
constexpr PascalTokenType PT_MINUS = PascalTokenType::MINUS;
constexpr PascalTokenType PT_STAR = PascalTokenType::STAR;
constexpr PascalTokenType PT_SLASH = PascalTokenType::SLASH;
constexpr PascalTokenType PT_COLON_EQUALS = PascalTokenType::COLON_EQUALS;
constexpr PascalTokenType PT_DOT = PascalTokenType::DOT;
constexpr PascalTokenType PT_COMMA = PascalTokenType::COMMA;
constexpr PascalTokenType PT_SEMICOLON = PascalTokenType::SEMICOLON;
constexpr PascalTokenType PT_COLON = PascalTokenType::COLON;
constexpr PascalTokenType PT_QUOTE = PascalTokenType::QUOTE;
constexpr PascalTokenType PT_EQUALS = PascalTokenType::EQUALS;
constexpr PascalTokenType PT_NOT_EQUALS = PascalTokenType::NOT_EQUALS;

constexpr PascalTokenType PT_LESS_THAN = PascalTokenType::LESS_THAN;
constexpr PascalTokenType PT_LESS_EQUALS = PascalTokenType::LESS_EQUALS;
constexpr PascalTokenType PT_GREATER_EQUALS = PascalTokenType::GREATER_EQUALS;
constexpr PascalTokenType PT_GREATER_THAN = PascalTokenType::GREATER_THAN;
constexpr PascalTokenType PT_LEFT_PAREN = PascalTokenType::LEFT_PAREN;
constexpr PascalTokenType PT_RIGHT_PAREN = PascalTokenType::RIGHT_PAREN;
constexpr PascalTokenType PT_LEFT_BRACKET = PascalTokenType::LEFT_BRACKET;
constexpr PascalTokenType PT_RIGHT_BRACKET = PascalTokenType::RIGHT_BRACKET;
constexpr PascalTokenType PT_LEFT_BRACE = PascalTokenType::LEFT_BRACE;
constexpr PascalTokenType PT_RIGHT_BRACE = PascalTokenType::RIGHT_BRACE;
constexpr PascalTokenType PT_UP_ARROW = PascalTokenType::UP_ARROW;
constexpr PascalTokenType PT_DOT_DOT = PascalTokenType::DOT_DOT;

constexpr PascalTokenType PT_IDENTIFIER = PascalTokenType::IDENTIFIER;
constexpr PascalTokenType PT_INTEGER = PascalTokenType::INTEGER;
constexpr PascalTokenType PT_REAL = PascalTokenType::REAL;
constexpr PascalTokenType PT_STRING = PascalTokenType::STRING;
constexpr PascalTokenType PT_ERROR = PascalTokenType::ERROR;
constexpr PascalTokenType PT_END_OF_FILE = PascalTokenType::END_OF_FILE;

class PascalToken : public Token
{
public:
    static map<string, PascalTokenType> RESERVED_WORDS;
    static map<string, PascalTokenType> SPECIAL_SYMBOLS;
    static map<PascalTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    cppToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::cpp

#endif /* WCI_FRONTEND_CPP_CPPTOKEN_H_ */
