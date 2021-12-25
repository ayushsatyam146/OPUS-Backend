#include "SyntaxKind.hpp"
#include <string>
#include <vector>

class SyntaxFacts  {
public:
    int GetUnaryOperatorPrecedence(SyntaxKind kind);
    int GetBinaryOperatorPrecedence(SyntaxKind kind);
    SyntaxKind GetKeywordKind(std::string text);
    std::string GetText(SyntaxKind kind);
    std::vector<SyntaxKind> SyntaxFacts::GetBinaryOperatorKinds();
    std::vector<SyntaxKind> SyntaxFacts::GetUnaryOperatorKinds();
};