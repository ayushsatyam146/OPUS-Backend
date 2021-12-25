#pragma once 
#include "SyntaxNode.hpp"
#include<string>

class SyntaxToken : public SyntaxNode{
public:    

    SyntaxKind Kind ;
    int Position ;
    std::string Text ;
    int Value ;
    std::vector<SyntaxNode> Children;
    
    SyntaxToken(SyntaxKind kind, int position, std::string text, int value);
    SyntaxToken();
    std::vector<SyntaxNode> GetChildren();
    friend bool operator== (const SyntaxToken& syntaxToken1, const SyntaxToken& syntaxToken2);
};

bool operator== (const SyntaxToken& syntaxToken1, const SyntaxToken& syntaxToken2);