#include "Binary_Expr_Node.h"
#include <iostream>
#include "Number_Node.h"

Binary_Expr_Node::Binary_Expr_Node (void)
:left_(new Number_Node (0) ), right_(new Number_Node (0) ), num1_(0), num2_(0)
{
	
}

Binary_Expr_Node::Binary_Expr_Node (Expr_Node * left, Expr_Node * right)
:left_(left), right_(right), num1_(0), num2_(0)
{
	
}

Binary_Expr_Node::~Binary_Expr_Node (void)
{
	delete left_;
	delete right_;
}

int Binary_Expr_Node::eval (void)
{
	num1_=this->left_->eval();
	num2_=this->right_->eval();
	int num3=execute(num1_, num2_);
	return num3;
}



void Binary_Expr_Node::set_children(Expr_Node * l, Expr_Node * r)
{
	if(this->left_!=NULL)
	{
		//delete left_;
		this->left_=l;
	}
	else
	{
		this->left_=l;
	}
	if(this->right_!=NULL)
	{
		//delete right_;
		this->right_=r;
	}
	else
	{
		this->right_=r;
	}
}