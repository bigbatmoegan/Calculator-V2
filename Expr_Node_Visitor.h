#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_


#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiplication_Expr_Node.h"
#include "Division_Expr_Node.h"
#include "Modulus_Expr_Node.h"
#include "Number_Node.h"


class Expr_Node_Visitor {
public:
	//Default Constructor
	Expr_Node_Visitor (void);
	
	//Visit each type of node
	virtual void Visit_Add_Node ( Add_Expr_Node * node)=0;
	
	virtual void Visit_Subtract_Node ( Subtract_Expr_Node * node)=0;
	
	virtual void Visit_Multiplication_Node ( Multiplication_Expr_Node * node)=0;
	
	virtual void Visit_Division_Node ( Division_Expr_Node * node)=0;
	
	virtual void Visit_Modulus_Node ( Modulus_Expr_Node * node)=0;
	
	virtual void Visit_Number_Node ( Number_Node * node)=0;
	
	//Destructor
	~Expr_Node_Visitor (void);
};

#endif