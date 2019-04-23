#include "Modulus_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Modulus_Expr_Node::Modulus_Expr_Node (void)
{
	
}

Modulus_Expr_Node::Modulus_Expr_Node (Expr_Node * left, Expr_Node * right)
: Binary_Expr_Node(left, right)
{
	
}

Modulus_Expr_Node::~Modulus_Expr_Node (void)
{
	
}

int Modulus_Expr_Node::execute(int num1, int num2)
{
	if(num2==0)
	{
		throw std::logic_error("Can not modulo by 0");
	}
	else
	{
		return num1%num2;
	}
}

void Modulus_Expr_Node::accept (Expr_Node_Visitor * v)
{
	v->Visit_Modulus_Node (this);
}