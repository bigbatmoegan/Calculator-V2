#ifndef _ADD_EXPR_NODE_H_
#define _ADD_EXPR_NODE_H_


#include "Binary_Expr_Node.h"

class Expr_Node_Visitor;


class Add_Expr_Node : public Binary_Expr_Node {
public:
	//Default constructor
	Add_Expr_Node (void);
	
	//Constructor with number nodes
	Add_Expr_Node (Expr_Node * left, Expr_Node * right);
	
	//Get sum of numbers
	virtual int execute (int num1, int num2);
		
	//Accept visitor
	virtual void accept (Expr_Node_Visitor * v);

	//Destructor
	~Add_Expr_Node (void);

};

#endif