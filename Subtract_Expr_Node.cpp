#include "Subtract_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Subtract_Expr_Node::Subtract_Expr_Node (void)
{
	
}

Subtract_Expr_Node::Subtract_Expr_Node (Expr_Node * left, Expr_Node * right)
: Binary_Expr_Node(left, right)
{
	
}

Subtract_Expr_Node::~Subtract_Expr_Node (void)
{
	
}

int Subtract_Expr_Node::execute(int num1, int num2)
{
	return num1-num2;
}

void Subtract_Expr_Node::accept (Expr_Node_Visitor * v)
{
	v->Visit_Subtract_Node (this);
}
