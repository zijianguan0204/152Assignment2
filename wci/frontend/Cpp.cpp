/**
 * <h1>Parser</h1>
 *
 * <p>A language-independent framework class.  This abstract parser class
 * will be implemented by language-specific subclasses.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "Cpp.h"
#include "../intermediate/SymTab.h"
#include "../intermediate/ICode.h"
#include "../message/Message.h"
#include "../message/MessageListener.h"

namespace wci { namespace frontend {

Cpp::Cpp(Scanner *scanner)
    : scanner(scanner), symtab(nullptr), icode(nullptr)
{
}

Cpp::~Cpp()
{
}

MessageHandler Cpp::message_handler;

Scanner *Cpp::get_scanner() const { return scanner; }

SymTab *Cpp::get_symtab() const { return symtab; }

ICode *Cpp::get_icode() const { return icode; }

MessageHandler& Cpp::get_message_handler() const
{
    return message_handler;
}

Token *Cpp::current_token()
{
    return scanner->current_token();
}

Token *Cpp::next_token(Token *prev_token) throw (string)
{
    return scanner->next_token(prev_token);
}

void Cpp::add_message_listener(MessageListener *listener)
{
    message_handler.add_listener(listener);
}

void Cpp::send_message(Message& message) const
{
    message_handler.send_message(message);
}

}} // namespace wci::frontend
