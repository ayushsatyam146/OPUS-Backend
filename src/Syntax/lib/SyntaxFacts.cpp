#include "../include/SyntaxFacts.hpp"
#include <string>
#include <vector>

class SyntaxFacts  {
    public:
    int GetUnaryOperatorPrecedence(SyntaxKind kind)
    {
        switch (kind)
        {
            case SyntaxKind::PlusToken:
            case SyntaxKind::MinusToken:
            case SyntaxKind::BangToken:
                return 6;

            default:
                return 0;
        }
    }

    int GetBinaryOperatorPrecedence(SyntaxKind kind)
    {
        switch (kind)
        {
            case SyntaxKind::StarToken:
            case SyntaxKind::SlashToken:
                return 5;

            case SyntaxKind::PlusToken:
            case SyntaxKind::MinusToken:
                return 4;

            case SyntaxKind::EqualsEqualsToken:
            case SyntaxKind::BangEqualsToken:
            case SyntaxKind::LessToken:
            case SyntaxKind::LessOrEqualsToken:
            case SyntaxKind::GreaterToken:
            case SyntaxKind::GreaterOrEqualsToken:
                return 3;

            case SyntaxKind::AmpersandAmpersandToken:
                return 2;

            case SyntaxKind::PipePipeToken:
                return 1;

            default:
                return 0;
        }
    }

    SyntaxKind GetKeywordKind(std::string text)
    {
        if (text == "else"){
            return SyntaxKind::ElseKeyword;
        }
        else if (text == "false"){
            return SyntaxKind::FalseKeyword;
        }
        else if (text == "for"){
            return SyntaxKind::ForKeyword;
        }
        else if (text == "if"){
            return SyntaxKind::IfKeyword;
        }
        else if (text == "let"){
            return SyntaxKind::LetKeyword;
        }
        else if (text == "to"){
            return SyntaxKind::ToKeyword;
        }
        else if (text == "true"){
            return SyntaxKind::TrueKeyword;
        }
        else if (text == "var"){
            return SyntaxKind::VarKeyword;
        }
        else if (text == "while"){
            return SyntaxKind::WhileKeyword;
        }
        else{
            return SyntaxKind::IdentifierToken;
        }
    }

    std::vector<SyntaxKind> GetUnaryOperatorKinds(){
        std::vector<SyntaxKind> PositiveUnaryOperatorPrecedenceKinds;
        for (auto kind : SyntaxKindText){
            if (GetUnaryOperatorPrecedence(kind.first) > 0){
                PositiveUnaryOperatorPrecedenceKinds.push_back(kind.first);
            }
        }
    }

    std::vector<SyntaxKind> GetBinaryOperatorKinds(){
        std::vector<SyntaxKind> PositiveBinaryOperatorPrecedenceKinds;
        for (auto kind : SyntaxKindText){
            if (GetBinaryOperatorPrecedence(kind.first) > 0){
                PositiveBinaryOperatorPrecedenceKinds.push_back(kind.first);
            }
        }
    }

    std::string GetText(SyntaxKind kind){
        if(kind == SyntaxKind::PlusToken){
            return "+";
        }
        else if (kind == SyntaxKind::MinusToken){
            return "-";
        }
        else if (kind == SyntaxKind::StarToken){
            return "*";
        }
        else if (kind == SyntaxKind::SlashToken){
            return "/";
        }
        else if (kind == SyntaxKind::BangToken){
            return "!";
        }
        else if (kind == SyntaxKind::EqualsToken){
            return "=";
        }
        else if (kind == SyntaxKind::LessToken){
            return "<";
        }
        else if (kind == SyntaxKind::LessOrEqualsToken){
            return "<=";
        }
        else if (kind == SyntaxKind::GreaterToken){
            return ">";
        }
        else if (kind == SyntaxKind::GreaterOrEqualsToken){
            return ">=";
        }
        else if (kind == SyntaxKind::AmpersandAmpersandToken){
            return "&&";
        }
        else if (kind == SyntaxKind::PipePipeToken){
            return "||";
        }
        else if (kind == SyntaxKind::EqualsEqualsToken){
            return "==";
        }
        else if (kind == SyntaxKind::BangEqualsToken){
            return "!=";
        }
        else if (kind == SyntaxKind::OpenParenthesisToken){
            return "(";
        }
        else if (kind == SyntaxKind::CloseParenthesisToken){
            return ")";
        }
        else if (kind == SyntaxKind::OpenBraceToken){
            return "{";
        }
        else if (kind == SyntaxKind::CloseBraceToken){
            return "}";
        }
        else if (kind == SyntaxKind::ElseKeyword){
            return "else";
        }
        else if (kind == SyntaxKind::FalseKeyword){
            return "false";
        }
        else if (kind == SyntaxKind::ForKeyword){
            return "for";
        }
        else if (kind == SyntaxKind::IfKeyword){
            return "if";
        }
        else if (kind == SyntaxKind::LetKeyword){
            return "let";
        }
        else if (kind == SyntaxKind::ToKeyword){
            return "to";
        }
        else if (kind == SyntaxKind::TrueKeyword){
            return "true";
        }
        else if (kind == SyntaxKind::VarKeyword){
            return "var";
        }
        else if (kind == SyntaxKind::WhileKeyword){
            return "while";
        }
        else {
            return nullptr;
        }
        
    }
};