#include "../include/SyntaxFacts.hpp"
#include <string>
#include <vector>

int SyntaxFacts::GetUnaryOperatorPrecedence(SyntaxKind kind)
{

    if (
    kind == SyntaxKind::PlusToken ||
    kind == SyntaxKind::MinusToken ||
    kind == SyntaxKind::BangToken
    )
        return 6;
 
    return 0;
}

int SyntaxFacts::GetBinaryOperatorPrecedence(SyntaxKind kind)
{
    if (kind==SyntaxKind::StarToken || kind==SyntaxKind::SlashToken)
        return 5;

    else if (kind==SyntaxKind::PlusToken || kind==SyntaxKind::MinusToken)
        return 4;

    else if (
    kind==SyntaxKind::EqualsEqualsToken ||
    kind==SyntaxKind::BangEqualsToken ||
    kind==SyntaxKind::LessToken ||
    kind==SyntaxKind::LessOrEqualsToken ||
    kind==SyntaxKind::GreaterToken ||
    kind==SyntaxKind::GreaterOrEqualsToken 
    )
        return 3;

    else if (kind==SyntaxKind::AmpersandAmpersandToken)
        return 2;

    else if (kind==SyntaxKind::PipePipeToken)
        return 1;
 
    return 0;
}

SyntaxKind SyntaxFacts::GetKeywordKind(std::string text)
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

std::vector<SyntaxKind> SyntaxFacts::GetUnaryOperatorKinds(){
    std::vector<SyntaxKind> PositiveUnaryOperatorPrecedenceKinds;
    for (auto kind : SyntaxKindText){
        if (GetUnaryOperatorPrecedence(kind.first) > 0){
            PositiveUnaryOperatorPrecedenceKinds.push_back(kind.first);
        }
    }
    return PositiveUnaryOperatorPrecedenceKinds;
}

std::vector<SyntaxKind> SyntaxFacts::GetBinaryOperatorKinds(){
    std::vector<SyntaxKind> PositiveBinaryOperatorPrecedenceKinds;
    for (auto kind : SyntaxKindText){
        if (GetBinaryOperatorPrecedence(kind.first) > 0){
            PositiveBinaryOperatorPrecedenceKinds.push_back(kind.first);
        }
    }
    return PositiveBinaryOperatorPrecedenceKinds;
}

std::string SyntaxFacts::GetText(SyntaxKind kind){
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