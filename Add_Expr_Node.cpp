#include "Add_Expr_Node.h"
#include "Expr_Node_Visitor.h"


Add_Expr_Node::Add_Expr_Node (void)
:Binary_Expr_Node()
{
	
}

Add_Expr_Node::Add_Expr_Node (Expr_Node * left, Expr_Node * right)
:Binary_Expr_Node(left, right)
{
	
}

Add_Expr_Node::~Add_Expr_Node (void)
{
	
}

int Add_Expr_Node::execute(int num1, int num2)
{
	return num1+num2;
}

void Add_Expr_Node::accept (Expr_Node_Visitor * v)
{
	v->Visit_Add_Node (this);
}