#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Stack.h"
#include "Binary_Expr_Node.h"
#include "Number_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiplication_Expr_Node.h"
#include "Division_Expr_Node.h"
#include "Modulus_Expr_Node.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

class Expr_Tree_Builder : public Expr_Builder {
public:
	//Default constructor
	Expr_Tree_Builder (void);
	
	//Start Expression
	virtual void start_expression (void);
	
	//Building of each node
	virtual Number_Node* build_number (int n);
	
	virtual Add_Expr_Node* build_add_node (void);
	
	virtual Subtract_Expr_Node* build_subtract_node (void);
	
	virtual Multiplication_Expr_Node* build_multiply_node (void);
	
	virtual Division_Expr_Node* build_divide_node (void);
	
	virtual Modulus_Expr_Node* build_modulus_node (void);
	
	virtual Expr_Node * get_expression (void);
	
	//Parsing the infix expression
	bool parse_expr (const std::string & infix);
	
	int precedence(std::string c);
	
	virtual ~Expr_Tree_Builder (void);
	
private:
	//current tree
	Expr_Node * tree_;
	
	//temp node to add to tree
	Expr_Node * temp;
	
	//temp number nodes to pass into operation constructor
	Expr_Node * leftnumber;
	
	Expr_Node * rightnumber;
};

#endif