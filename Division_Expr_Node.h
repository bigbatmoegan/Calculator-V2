#ifndef _DIVISION_EXPR_NODE_H_
#define _DIVISION_EXPR_NODE_H_

#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include <stdexcept>

class Expr_Node_Visitor;

class Division_Expr_Node : public Binary_Expr_Node {
public:
	//Default constructor
	Division_Expr_Node (void);
	
	//Constructor with number nodes
	Division_Expr_Node (Expr_Node * right, Expr_Node * left);
	
	//Get sum of numbers
	virtual int execute (int num1, int num2);
	
	//Destructor
	~Division_Expr_Node (void);
	
	//Accept visitor
	virtual void accept (Expr_Node_Visitor * v);

};

#endif