#include "Eval_Expr_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree (void)
:result_(0)
{
	
}

void Eval_Expr_Tree::Visit_Add_Node ( Add_Expr_Node * node)
{
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Subtract_Node ( Subtract_Expr_Node * node)
{
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Multiplication_Node ( Multiplication_Expr_Node * node)
{
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Division_Node ( Division_Expr_Node * node)
{
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Modulus_Node ( Modulus_Expr_Node * node)
{
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Number_Node ( Number_Node * node)
{
	result_=node->eval();
}

int Eval_Expr_Tree::result (void) const
{
	return this->result_;
}

Eval_Expr_Tree::~Eval_Expr_Tree (void)
{
	
}
