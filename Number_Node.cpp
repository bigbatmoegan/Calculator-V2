#include "Number_Node.h"
#include "Expr_Node_Visitor.h"

Number_Node::Number_Node (void)
: value(0)
{
	
}

Number_Node::Number_Node (int num)
: value(num)
{
	
}

int Number_Node::eval (void)
{
	return value;
}

Number_Node::~Number_Node (void)
{
	
}

void Number_Node::accept (Expr_Node_Visitor * v)
{
	v->Visit_Number_Node (this);
}

void Number_Node::set_children (Expr_Node * l, Expr_Node * r)
{
	//
}