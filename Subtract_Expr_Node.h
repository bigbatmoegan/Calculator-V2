#ifndef _SUBTRACT_EXPR_NODE_H_
#define _SUBTRACT_EXPR_NODE_H_

#include "Expr_Node.h"
#include "Binary_Expr_Node.h"

class Subtract_Expr_Node : public Binary_Expr_Node {
public:
	//Default constructor
	Subtract_Expr_Node (void);
	
	//Constructor with number nodes
	Subtract_Expr_Node (Expr_Node * right, Expr_Node * left);
	
	//Get sum of numbers
	virtual int execute (int num1, int num2);
	
	//Accept visitor
	virtual void accept (Expr_Node_Visitor * v);
	
	//Destructor
	~Subtract_Expr_Node (void);

};

#endif