#ifndef _MULTIPLICATION_EXPR_NODE_H_
#define _MULTIPLICATION_EXPR_NODE_H_


#include "Binary_Expr_Node.h"

class Expr_Node_Visitor;

class Multiplication_Expr_Node : public Binary_Expr_Node {
public:
	//Default constructor
	Multiplication_Expr_Node (void);
	
	//Constructor with number nodes
	Multiplication_Expr_Node (Expr_Node * right, Expr_Node * left);
	
	//Get sum of numbers
	virtual int execute (int num1, int num2);
	
	//Accept visitor
	virtual void accept (Expr_Node_Visitor * v);
	
	//Destructor
	~Multiplication_Expr_Node (void);

};

#endif