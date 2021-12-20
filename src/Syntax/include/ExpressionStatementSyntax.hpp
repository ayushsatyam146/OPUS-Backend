#pragma once
#include "StatementSyntax.hpp"
#include "ExpressionSyntax.hpp"

class ExpressionStatementSyntax : StatementSyntax {
public: 
    ExpressionSyntax Expression;
    ExpressionStatementSyntax(ExpressionSyntax expression) ;
};