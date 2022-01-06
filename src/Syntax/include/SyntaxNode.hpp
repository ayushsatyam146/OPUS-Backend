#pragma once 
#include "SyntaxKind.hpp"
#include<vector>
#include<iostream>
#include <string>

class SyntaxNode {
public:    
    SyntaxKind Kind; 
    std::vector<SyntaxNode> GetChildren(); 
};