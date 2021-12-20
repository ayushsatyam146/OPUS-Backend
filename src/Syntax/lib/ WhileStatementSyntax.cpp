#include " WhileStatementSyntax.hpp"

WhileStatementSyntax::WhileStatementSyntax(SyntaxToken whileKeyword, ExpressionSyntax condition, StatementSyntax body){
    SyntaxKind Kind = SyntaxKind::WhileStatement;
    WhileKeyword = whileKeyword;
    Condition = condition;
    Body = body;
}