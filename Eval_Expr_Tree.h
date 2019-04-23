#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor {
public:
	//Default constructor
	Eval_Expr_Tree (void);
	
	//visiting each node to do required operation
	virtual void Visit_Add_Node ( Add_Expr_Node * node);
	
	virtual void Visit_Subtract_Node ( Subtract_Expr_Node * node);
	
	virtual void Visit_Multiplication_Node ( Multiplication_Expr_Node * node);
	
	virtual void Visit_Division_Node ( Division_Expr_Node * node);
	
	virtual void Visit_Modulus_Node ( Modulus_Expr_Node * node);
	
	virtual void Visit_Number_Node ( Number_Node * node);
	
	//get result
	int result (void) const;
	
	//Destructor
	~Eval_Expr_Tree (void);
	
private:
	int result_;
	
};

#endif