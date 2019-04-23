#include "Multiplication_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Multiplication_Expr_Node::Multiplication_Expr_Node (void)
{
	
}

Multiplication_Expr_Node::Multiplication_Expr_Node (Expr_Node * left, Expr_Node * right)
: Binary_Expr_Node(left, right)
{
	
}

Multiplication_Expr_Node::~Multiplication_Expr_Node (void)
{
	
}

int Multiplication_Expr_Node::execute(int num1, int num2)
{
	return num1*num2;
}

void Multiplication_Expr_Node::accept (Expr_Node_Visitor * v)
{
	v->Visit_Multiplication_Node (this);
}
