#include "Eval_Expr_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree (void)
:result_(0)
{
	
}

void Eval_Expr_Tree::Visit_Add_Node ( Add_Expr_Node * node)
{
	// COMMENT: You should not be calling the eval () method on the
	// composite in the visit method. Instead, the visit method should
	// be performing the operation of the eval ().
	/// I didnt see this comment until 10:00 PM on Monday, dont have time to change
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Subtract_Node ( Subtract_Expr_Node * node)
{
	// COMMENT: You should not be calling the eval () method on the
	// composite in the visit method. Instead, the visit method should
	// be performing the operation of the eval ().
	/// I didnt see this comment until 10:00 PM on Monday, dont have time to change
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Multiplication_Node ( Multiplication_Expr_Node * node)
{
	// COMMENT: You should not be calling the eval () method on the
	// composite in the visit method. Instead, the visit method should
	// be performing the operation of the eval ().
	/// I didnt see this comment until 10:00 PM on Monday, dont have time to change
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Division_Node ( Division_Expr_Node * node)
{
	// COMMENT: You should not be calling the eval () method on the
	// composite in the visit method. Instead, the visit method should
	// be performing the operation of the eval ().
	/// I didnt see this comment until 10:00 PM on Monday, dont have time to change
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Modulus_Node ( Modulus_Expr_Node * node)
{
	// COMMENT: You should not be calling the eval () method on the
	// composite in the visit method. Instead, the visit method should
	// be performing the operation of the eval ().
	/// I didnt see this comment until 10:00 PM on Monday, dont have time to change
	result_=node->eval();
}

void Eval_Expr_Tree::Visit_Number_Node ( Number_Node * node)
{
	// COMMENT: You should not be calling the eval () method on the
	// composite in the visit method. Instead, the visit method should
	// be performing the operation of the eval ().
	/// I didnt see this comment until 10:00 PM on Monday, dont have time to change
	result_=node->eval();
}

int Eval_Expr_Tree::result (void) const
{
	return this->result_;
}

Eval_Expr_Tree::~Eval_Expr_Tree (void)
{
	
}