#include "../include/lexer.hpp"

std::string GetText(SyntaxKind kind) {
    switch (kind) {
        case SyntaxKind::PlusToken:
            return "+";
        case SyntaxKind::MinusToken:
            return "-";
        case SyntaxKind::StarToken:
            return "*";
        case SyntaxKind::SlashToken:
            return "/";
        case SyntaxKind::BangToken:
            return "!";
        case SyntaxKind::EqualsToken:
            return "=";
        case SyntaxKind::AmpersandAmpersandToken:
            return "&&";
        case SyntaxKind::PipePipeToken:
            return "||";
        case SyntaxKind::EqualsEqualsToken:
            return "==";
        case SyntaxKind::BangEqualsToken:
            return "!=";
        case SyntaxKind::OpenParenthesisToken:
            return "(";
        case SyntaxKind::CloseParenthesisToken:
            return ")";
        case SyntaxKind::FalseKeyword:
            return "false";
        case SyntaxKind::TrueKeyword:
            return "true";
        default:
            return "null";
    }
}

SyntaxKind GetKeywordKind(std::string text) {
    if(text == "true"){
        return SyntaxKind::TrueKeyword;
    }
    else if(text == "false"){
        return SyntaxKind::FalseKeyword;
    }
    else {
        return SyntaxKind::IdentifierToken;
    }
}



void Lexer::ReadWhiteSpace() {
    while (Current() == ' ') {
        _position++;
    }
    _kind = SyntaxKind::WhitespaceToken;
}

void Lexer::ReadNumberToken() { 
    while (isdigit(Current())) {
        _position++;
    }
    int length = _position - _start;
    std::string text = _text.substr(_start, length);
    int value = stoi(text);
    _value = value;
    _kind = SyntaxKind::NumberToken;
}

void Lexer::ReadIdentifierOrKeyword() {
    while (isalpha(Current())) _position++;
    int length = _position - _start;
    std::string text = _text.substr(_start, length);
    _kind = GetKeywordKind(text);
}
    
char Lexer::Peek(int offset){
    int index = _position + offset;
    if (index >= _text.length()) return '\0';
    return _text[index];
}

char Lexer::Current() {return Peek(0);}
char Lexer::Lookahead() {return Peek(1);}

Lexer::Lexer(std::string text){
    _text = text;
}    

SyntaxToken Lexer::Lex()
{
    _start = _position;
    _kind = SyntaxKind::BadToken;
    _value = 0;

    switch (Current()) {
        case '\0':
            _kind = SyntaxKind::EndOfFileToken; 
            break;
        case '+':
            _kind = SyntaxKind::PlusToken;
            _position++; 
            break;
        case '-':
            _kind = SyntaxKind::MinusToken;
            _position++;
            break;
        case '*':
            _kind = SyntaxKind::StarToken;
            _position++;
            break;
        case '/':
            _kind = SyntaxKind::SlashToken;
            _position++;
            break;
        case '(':
            _kind = SyntaxKind::OpenParenthesisToken;
            _position++;
            break;
        case ')':
            _kind = SyntaxKind::CloseParenthesisToken;
            _position++;
            break;
        case '&':
            if (Lookahead() == '&') {
                _kind = SyntaxKind::AmpersandAmpersandToken;
                _position += 2;
                break;
            }
            break;
        case '|':
            if (Lookahead() == '|') {
                _kind = SyntaxKind::PipePipeToken;
                _position += 2;
                break;
            }
            break;
        case '=':
            _position++;
            if (Current() != '=') {
                _kind = SyntaxKind::EqualsToken;
            }
            else {
                _position++;
                _kind = SyntaxKind::EqualsEqualsToken;
            }
            break;
        case '!':
            _position++;
            if (Current() != '=') {
                _kind = SyntaxKind::BangToken;
            }
            else {
                _kind = SyntaxKind::BangEqualsToken;
                _position++;
            }
            break;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            ReadNumberToken();
            break;
        case ' ':
        case '\t':
        case '\n':
        case '\r':
            ReadWhiteSpace();
            break;
        default:
            if (isalpha(Current())) {
                ReadIdentifierOrKeyword();
            }
            else if ((Current() == ' ')) {
                ReadWhiteSpace();
            }
            else {
                _position++;
            }
            break;
    }

    int length = _position - _start;
    std::string text = GetText(_kind); 

    if (text == "null") text = _text.substr(_start, length); 
    return *new SyntaxToken(_kind, _start, text, _value);
} 
    
