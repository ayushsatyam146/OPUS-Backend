#pragma once
#include "SyntaxKind.hpp"
#include "SyntaxNode.hpp"
#include "SyntaxToken.hpp"
#include <string>
#include <vector>

class SyntaxFacts  {
public:
    static int GetUnaryOperatorPrecedence(SyntaxKind kind);
    static int GetBinaryOperatorPrecedence(SyntaxKind kind);
    static SyntaxKind GetKeywordKind(std::string text);
    static std::string GetText(SyntaxKind kind);
    static std::vector<SyntaxKind> GetBinaryOperatorKinds();
    static std::vector<SyntaxKind> GetUnaryOperatorKinds();
    static std::string PrettyPrint(std::string writer, SyntaxNode node, std::string indent , bool isLast);
};