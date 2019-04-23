#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_


#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node {
public:
	//Default constructor
	Binary_Expr_Node (void);
	
	//evaluation
	virtual int eval (void);
	
	//Get required operation
	virtual int execute (int num1, int num2)=0;
	
	//Destructor	
	virtual ~Binary_Expr_Node (void);
	
	//Set children
	void set_children (Expr_Node * l, Expr_Node * r);
	
protected:
	//Constructor with  children passed in
	Binary_Expr_Node(Expr_Node * left, Expr_Node * right);
	
	//Left and right child
	Expr_Node * left_;
	Expr_Node * right_;
	
	//Values to be passed in
	int num1_;
	int num2_;
};

#endif