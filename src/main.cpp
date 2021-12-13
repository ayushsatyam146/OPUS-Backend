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

    std::vector<SyntaxNode> Children;
    std::vector<SyntaxNode> GetChildren(){
        return Children;
    } 
};

class Lexer{
private:    
    std::string _text;
    int _position;

    char Peek(int offset){
        int index = _position + offset;
        if(index >= _text.size()) return '\0';
        return _text[index];
    }

    char Current() { return Peek(0); }

    char Lookahead() { return Peek(1); }

    void Next() { _position++; }
    
public:
    Lexer(std::string text){
        _text = text;
    }

    SyntaxToken Lex()
    {
        if (_position >= _text.length())
            return *new SyntaxToken(SyntaxKind::EndOfFileToken, _position, "\0", NULL);

        int start = _position;

        if ( isdigit(Current()) ) {
            while (isdigit(Current())) Next();
            int length = _position - start;
            std::string text = _text.substr(start, length);

            // do exception handling for stoi function in case text doesn't resolves to int
            int value = stoi(text);
            return *new SyntaxToken(SyntaxKind::NumberToken, start, text, value);
        }

        if (Current() == ' ') {
            while (Current() == ' ') Next();
            int length = _position - start;
            std::string text = _text.substr(start, length);
            return *new SyntaxToken(SyntaxKind::WhitespaceToken, start, text, NULL);
        }

        if ( isalpha(Current()) ) {
            while (isalpha(Current())) Next();
            int length = _position - start;
            std::string text = _text.substr(start, length); 
            if(text == "true"){
                return *new SyntaxToken(SyntaxKind::TrueKeyword, start, text, NULL);
            } else if(text == "false"){
                return *new SyntaxToken(SyntaxKind::FalseKeyword, start, text, NULL);
            } else{
                return *new SyntaxToken(SyntaxKind::IdentifierToken, start, text, NULL);
            }
        }

        switch (Current())
        {
            case '+':
                return *new SyntaxToken(SyntaxKind::PlusToken, _position++, "+", NULL);
            case '-':
                return *new SyntaxToken(SyntaxKind::MinusToken, _position++, "-", NULL);
            case '*':
                return *new SyntaxToken(SyntaxKind::StarToken, _position++, "*", NULL);
            case '/':
                return *new SyntaxToken(SyntaxKind::SlashToken, _position++, "/", NULL);
            case '(':
                return *new SyntaxToken(SyntaxKind::OpenParenthesisToken, _position++, "(", NULL);
            case ')':
                return *new SyntaxToken(SyntaxKind::CloseParenthesisToken, _position++, ")", NULL);
            case '&':
                if (Lookahead() == '&')
                {
                    _position += 2;
                    return *new SyntaxToken(SyntaxKind::AmpersandAmpersandToken, start, "&&", NULL);
                }
                break;
            case '|':
                if (Lookahead() == '|') {
                    _position += 2;
                    return *new SyntaxToken(SyntaxKind::PipePipeToken, start, "||", NULL);
                }
                break;
            case '=':
                if (Lookahead() == '=') {
                    _position += 2;
                    return *new SyntaxToken(SyntaxKind::EqualsEqualsToken, start, "==", NULL);
                } else {
                    _position += 1;
                    return *new SyntaxToken(SyntaxKind::EqualsToken, start, "=", NULL);
                }
            case '!':
                if (Lookahead() == '=') {
                    _position += 2;
                    return *new SyntaxToken(SyntaxKind::BangEqualsToken, start, "!=", NULL);
                } else {
                    _position += 1;
                    return *new SyntaxToken(SyntaxKind::BangToken, start, "!", NULL);
                }
        } 
    }
};


int main(){
    return 0;
}