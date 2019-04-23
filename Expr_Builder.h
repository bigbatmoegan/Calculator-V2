#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Number_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiplication_Expr_Node.h"
#include "Division_Expr_Node.h"
#include "Modulus_Expr_Node.h"
#include <string>

class Expr_Builder {
public:
	//Default Constructor
	Expr_Builder (void);
	
	virtual void start_expression (void)=0;
	
	//Building of each node to be implemented in subclass
	virtual Number_Node* build_number (int n)=0;
	
	virtual Add_Expr_Node* build_add_node (void)=0;
	
	virtual Subtract_Expr_Node* build_subtract_node (void)=0;
	
	virtual Multiplication_Expr_Node* build_multiply_node (void)=0;
	
	virtual Division_Expr_Node* build_divide_node (void)=0;
	
	virtual Modulus_Expr_Node* build_modulus_node (void)=0;
	
	//Get Expression
	virtual Expr_Node * get_expression (void)=0;
	
	//Destructor
	virtual ~Expr_Builder (void);
	
	//Pares
	virtual bool parse_expr (const std::string & infix)=0;
	
};

#endif