/*
 * cppToken.cpp
 *
 *  Created on: Feb 6, 2019
 *      Author: willgotu
 */

#include <string>
#include <vector>
#include <map>
#include "cppToken.h"

namespace wci { namespace frontend { namespace cpp {

using namespace std;

map<string, cppTokenType> cppToken::RESERVED_WORDS;
map<string, cppTokenType> cppToken::SPECIAL_SYMBOLS;
map<cppTokenType, string> cppToken::SPECIAL_SYMBOL_NAMES;

bool cppToken::INITIALIZED = false;

void cppToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
        "auto", "break", "case", "char", "class", "const", "continue", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "namespace", "operator", "protected", "public", "return", "static",
        "struct", "switch", "template", "this", "throw", "union", "void",
        "while"
    };

    vector<cppTokenType> rw_keys =
    {
    	cppTokenType::AUTO,
		cppTokenType::BREAK,
		cppTokenType::CASE,
		cppTokenType::CHAR,
		cppTokenType::CLASS,
		cppTokenType::CONST,
		cppTokenType::CONTINUE,
		cppTokenType::DO,

		cppTokenType::DOUBLE,
		cppTokenType::ELSE,
		cppTokenType::ENUM,
		cppTokenType::EXTERN,
		cppTokenType::FLOAT,
		cppTokenType::FOR,
		cppTokenType::GOTO,
		cppTokenType::IF,

		cppTokenType::INT,
		cppTokenType::LONG,
		cppTokenType::NAMESPACE,
		cppTokenType::OPERATOR,
		cppTokenType::PROTECTED,
		cppTokenType::PUBLIC,
		cppTokenType::RETURN,
		cppTokenType::STATIC,

		cppTokenType::STRUCT,
		cppTokenType::SWITCH,
		cppTokenType::TEMPLATE,
		cppTokenType::THIS,
		cppTokenType::THROW,
		cppTokenType::UNION,
		cppTokenType::VOID,
		cppTokenType::WHILE
    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
        "~", "!", "@", "%", "^", "&", "*", "-", "+", "=",
		"|", "/", ":", ";", "?", "<", ">", ".", ",",
        "'", "\"", "(", ")", "[", "]", "{", "}",
		"++", "--",  "<<", ">>", "<=", ">=", "+=", "-=", "*=", "/=",
		"==", "|=", "%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&",
		"//", "/*", "*/"
    };

    vector<cppTokenType> ss_keys =
    {
		cppTokenType::NOT,
		cppTokenType::NOT EQUALS,
		cppTokenType::TEMPLATE,
		cppTokenType::MODULUS,
		cppTokenType::BITWISE XOR,
		cppTokenType::BITWISE AND,
		cppTokenType::VOID,
		cppTokenType::WHILE,
		cppTokenType::PLUS,
		cppTokenType::WHILE,

        PascalTokenType::PLUS,
        PascalTokenType::MINUS,
        PascalTokenType::STAR,
        PascalTokenType::SLASH,
        PascalTokenType::COLON_EQUALS,
        PascalTokenType::DOT,
        PascalTokenType::COMMA,
        PascalTokenType::SEMICOLON,
        PascalTokenType::COLON,
        PascalTokenType::QUOTE,
        PascalTokenType::EQUALS,
        PascalTokenType::NOT_EQUALS,

        PascalTokenType::LESS_THAN,
        PascalTokenType::LESS_EQUALS,
        PascalTokenType::GREATER_EQUALS,
        PascalTokenType::GREATER_THAN,
        PascalTokenType::LEFT_PAREN,
        PascalTokenType::RIGHT_PAREN,
        PascalTokenType::LEFT_BRACKET,
        PascalTokenType::RIGHT_BRACKET,
        PascalTokenType::LEFT_BRACE,
        PascalTokenType::RIGHT_BRACE,
        PascalTokenType::UP_ARROW,
        PascalTokenType::DOT_DOT
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
        "PLUS", "MINUS", "STAR", "SLASH", "COLON_EQUALS", "DOT", "COMMA",
        "SEMICOLON", "COLON", "QUOTE", "EQUALS", "NOT_EQUALS",

        "LESS_THAN", "LESS_EQUALS", "GREATER_EQUALS", "GREATER_THAN",
        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
        "LEFT_BRACE", "RIGHT_BRACE", "UP_ARROW", "DOT_DOT"
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

PascalToken::PascalToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::cpp



