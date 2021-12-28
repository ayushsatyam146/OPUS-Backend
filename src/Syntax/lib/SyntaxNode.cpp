#include "../include/SyntaxNode.hpp"
#include "../include/SyntaxToken.hpp" 

std::string SyntaxNode::PrettyPrint(std::string writer, SyntaxNode node, std::string indent , bool isLast)
{
    std::string marker = isLast ? "└──" : "├──";
 
    writer+=indent;
    writer+=marker;

 

    writer+= SyntaxKindText[node.Kind];


    // writer.WriteLine();
    writer+="\n";

    indent += isLast ? "   " : "│  ";

    std::vector<SyntaxNode> Children = node.GetChildren();

    // for (int i = 0; i < Children.size(); i++) {
    //     if(i != Children.size()-1){
    //         PrettyPrint(writer, Children[i], indent, false);
    //     } else {
    //         PrettyPrint(writer,Children[i], indent, true);
    //     }
    // }   

    return writer;
}

