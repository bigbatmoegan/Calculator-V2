#ifndef _MODULUS_EXPR_NODE_H_
#define _MODULUS_EXPR_NODE_H_

#include "Binary_Expr_Node.h"
#include <stdexcept>

class Expr_Node_Visitor;

class Modulus_Expr_Node : public Binary_Expr_Node {
public:
	//Default constructor
	Modulus_Expr_Node (void);
	
	//Constructor with number nodes
	Modulus_Expr_Node (Expr_Node * right, Expr_Node * left);
	
	//Get modulo of numbers
	virtual int execute (int num1, int num2);
	
	//Accept Visitor
	virtual void accept (Expr_Node_Visitor * v);
	
	//Destructor
	~Modulus_Expr_Node (void);

};

#endif