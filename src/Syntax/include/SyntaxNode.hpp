#pragma once 
#include "SyntaxKind.hpp"
#include<vector>

class SyntaxNode {
public:    
    SyntaxKind Kind; 
    std::vector<SyntaxNode> GetChildren();
    SyntaxNode(){}
};