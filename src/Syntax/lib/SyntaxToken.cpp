#include "../include/SyntaxToken.hpp"

SyntaxToken::SyntaxToken(SyntaxKind kind, int position, std::string text, int value) {
    Kind = kind;
    Position = position;
    Text = text;
    Value = value; 
}

SyntaxToken::SyntaxToken() {
    Kind = BadToken;
    Position = 0;
    Text = "";
    Value = 0; 
}

std::vector<SyntaxNode> SyntaxToken::GetChildren() {
    return Children;
} 

bool operator== (const SyntaxToken& syntaxToken1, const SyntaxToken& syntaxToken2)
{
    return (
        syntaxToken1.Kind == syntaxToken2.Kind &&
        syntaxToken1.Position == syntaxToken2.Position &&
        syntaxToken1.Text == syntaxToken2.Text &&
        syntaxToken1.Value == syntaxToken2.Value  
    );
}