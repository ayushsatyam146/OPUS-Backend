#pragma once
#include "SyntaxToken.hpp"

class Lexer {

private:
    std::string _text;
    int _position = 0;
    int _start;
    SyntaxKind _kind;
    int _value;

    void ReadWhiteSpace();
    void ReadNumberToken();
    void ReadIdentifierOrKeyword();
    char Peek(int offset);
    char Current();
    char Lookahead();

public:
    Lexer(std::string text);
    SyntaxToken Lex();    
};