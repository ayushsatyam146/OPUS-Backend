#include<string>
#include<vector>
#include<iostream>

#include "Syntax/include/Parser.hpp"
#include "Syntax/include/SyntaxTree.hpp"
#include "Syntax/include/SyntaxNode.hpp"

int main(){
    std::string inputText;
    inputText = "1";
    SyntaxTree syntaxTree(inputText);

    std::string PrintValue = SyntaxNode::PrettyPrint("",syntaxTree.Root,"",true);
    std::cout<<PrintValue<<"\n......................................\n";
    
    return 0;
}

