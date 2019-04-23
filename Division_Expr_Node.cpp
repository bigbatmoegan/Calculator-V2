#include "Division_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Division_Expr_Node::Division_Expr_Node (void)
{
	
}

Division_Expr_Node::Division_Expr_Node (Expr_Node * left, Expr_Node * right)
: Binary_Expr_Node(left, right)
{
	
}

Division_Expr_Node::~Division_Expr_Node (void)
{
	
}

int Division_Expr_Node::execute(int num1, int num2)
{
	if(num2==0)
	{
		throw std::logic_error("Can not divide by 0");
	}
	else
	{
		return num1/num2;
	}
}

void Division_Expr_Node::accept (Expr_Node_Visitor * v)
{
	v->Visit_Division_Node (this);
}