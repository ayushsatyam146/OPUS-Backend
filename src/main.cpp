#include<string>
#include<vector>
#include<iostream>

enum SyntaxKind {
    // Tokens
    BadToken,
    EndOfFileToken,
    WhitespaceToken,
    NumberToken,
    PlusToken,
    MinusToken,
    StarToken,
    SlashToken,
    BangToken,
    EqualsToken,
    AmpersandAmpersandToken,
    PipePipeToken,
    EqualsEqualsToken,
    BangEqualsToken,
    OpenParenthesisToken,
    CloseParenthesisToken,
    IdentifierToken,

    // Keywords
    FalseKeyword,
    TrueKeyword,

    // Expressions
    LiteralExpression,
    NameExpression,
    UnaryExpression,
    BinaryExpression,
    ParenthesizedExpression,
    AssignmentExpression,
};

class SyntaxNode {
public:    
    SyntaxKind Kind; 
    std::vector<SyntaxNode> GetChildren();
};

class SyntaxToken : SyntaxNode{
public:    

    SyntaxKind Kind ;
    int Position ;
    std::string Text ;
    int Value ;

    SyntaxToken(SyntaxKind kind, int position, std::string text, int value)
    {
        Kind = kind;
        Position = position;
        Text = text;
        Value = value; 
    }

    SyntaxToken()
    {
        Kind = BadToken;
        Position = 0;
        Text = "";
        Value = 0; 
    }

    std::vector<SyntaxNode> Children;
    std::vector<SyntaxNode> GetChildren(){
        return Children;
    } 
};

std::string GetText(SyntaxKind kind) {
    switch (kind)
    {
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

SyntaxKind GetKeywordKind(std::string text)
{
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

class Lexer {

private:
    std::string _text;
    int _position = 0;
    int _start;
    SyntaxKind _kind;
    int _value;

    void ReadWhiteSpace() {
        while (Current() == ' ') {
            _position++;
        }
        _kind = SyntaxKind::WhitespaceToken;
    }

    void ReadNumberToken() { 
        while (isdigit(Current())) {
            _position++;
        }
        int length = _position - _start;
        std::string text = _text.substr(_start, length);
        int value = stoi(text);
        _value = value;
        _kind = SyntaxKind::NumberToken;
    }

    void ReadIdentifierOrKeyword() {
        while (isalpha(Current())) _position++;
        int length = _position - _start;
        std::string text = _text.substr(_start, length);
        _kind = GetKeywordKind(text);
    }
    
    char Peek(int offset){
        int index = _position + offset;
        if (index >= _text.length()) return '\0';
        return _text[index];
    }
    char Current() {return Peek(0);}
    char Lookahead() {return Peek(1);}

public:
    Lexer(std::string text){
        _text = text;
    }    

    SyntaxToken Lex()
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
    
};

int main(){
    std::string text;
    // text = "123 + 18";
    std::vector <SyntaxToken> tokens;
    Lexer lexer(text);
    SyntaxToken token;
    
    while (token.Kind != SyntaxKind::EndOfFileToken){
        token = lexer.Lex();
        if( token.Kind != SyntaxKind::WhitespaceToken &&
            token.Kind != SyntaxKind::BadToken) 
        {
            tokens.push_back(token);
        }
    } 

    // For printing tokens for test 
    // for(int i = 0;i < tokens.size(); i++){
    //     SyntaxToken tok = tokens[i];
    //     std::cout<<"["<<tok.Kind<<", "<<tok.Position<<", "<<tok.Text<<", "<<tok.Value<<"]\n";
    // }
    return 0;
}