#include "Expr_Tree_Builder.h"
#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Stack.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiplication_Expr_Node.h"
#include "Modulus_Expr_Node.h"
#include "Division_Expr_Node.h"
#include "Number_Node.h"
#include <iostream>
#include <ctype.h>

Expr_Tree_Builder::Expr_Tree_Builder (void)
:tree_(new Add_Expr_Node), temp (new Add_Expr_Node)
{
	
}

void Expr_Tree_Builder::start_expression (void)
{
	leftnumber=new Number_Node (0);
	rightnumber=new Number_Node (0);
	temp= new Add_Expr_Node (leftnumber, rightnumber);
}

Number_Node* Expr_Tree_Builder::build_number (int n)
{
	return new Number_Node (n);
}

Add_Expr_Node* Expr_Tree_Builder::build_add_node (void)
{
	return new Add_Expr_Node ();
}

Subtract_Expr_Node* Expr_Tree_Builder::build_subtract_node (void)
{
	return new Subtract_Expr_Node ();
}

Multiplication_Expr_Node* Expr_Tree_Builder::build_multiply_node (void)
{
	return new Multiplication_Expr_Node ();
}

Division_Expr_Node* Expr_Tree_Builder::build_divide_node (void)
{
	return new Division_Expr_Node ();
}

Modulus_Expr_Node* Expr_Tree_Builder::build_modulus_node (void)
{
	return new Modulus_Expr_Node ();
}

Expr_Node * Expr_Tree_Builder::get_expression (void)
{
	return tree_;
}

int Expr_Tree_Builder::precedence(std::string c)
{
	if(c=="*" || c=="/" || c=="%")
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

Expr_Tree_Builder::~Expr_Tree_Builder (void)
{
	delete tree_;
	delete temp;
}


bool Expr_Tree_Builder::parse_expr (const std::string & infix)
{
	// COMMENT: Do not go from infix to postfix then to tree. Instead,
	// go directly from infix to tree. The extra step is not necessary.
	/// Could not get it working correctly without half way implementing
	/// a version of postfix
	
	std::istringstream input(infix);
	std::string token;
	Expr_Tree_Builder c;
	c.start_expression();
	//CREATE A STACK OF NUMBERS AND A STACK OF OPERATIONS
	//AND PUSH NUMBERS AT WILL, AND OPERATORS IF PEMDAS
	//ALLOWS, OTHERWISE POP
	Stack <Expr_Node *> numnode;
	Stack <Expr_Node *> opnode;
	Stack <std::string> operands;
	operands.push("A");
	while(!input.eof())
	{
		input >> token;
		//check if token is a number
		if(token!="*" && token!="/" && token!="+" && token!="-" && token!="(" && token!=")" && token!="%")
		{
			//check if variable 
			if(isalpha(token[0]))
			{
				//THIS IS VARAIBLE SUPPORT, WAS INCORPERATED IN FIRST SUBMISSION
				//NOT SURE WHY WAS DEDUCTED FOR "MISSING VARIABLE SUPPORT"
				std::string stringnum;
				std::cout << "Enter value for variable: ";
				std::cin >> stringnum;
				int numbers=stoi(stringnum);
				temp=c.build_number (numbers);
				numnode.push(temp);
			}
			else
			{
				int number=stoi(token);
				temp=c.build_number (number);
				numnode.push(temp);
			}
		}
		//check if (
		else if(token=="(")
		{
			operands.push(token);
		}
		else if(token==")")
		{
			while(operands.top()!="(")
			{
				temp=opnode.top();
				rightnumber=numnode.top();
				numnode.pop();
				leftnumber=numnode.top();
				numnode.pop();
				temp->set_children(leftnumber, rightnumber);
				tree_=temp;
				opnode.pop();
				operands.pop();
			}
			if(operands.top()=="(")
			{
				operands.pop();
			}
		}
		
		else //any operand is scanned
		{
			//Get precedence
			while(operands.top()!="A" && precedence(token)<precedence(operands.top()))
			{
				temp=opnode.top();
				opnode.pop();
				rightnumber=numnode.top();
				numnode.pop();
				leftnumber=numnode.top();
				numnode.pop();
				operands.pop();
				temp->set_children(leftnumber, rightnumber);
				tree_=temp;
			}
			operands.push(token);		
			if(token=="+")
			{
				temp=c.build_add_node();
				opnode.push(temp);
			}
			else if(token=="-")
			{
				temp=c.build_subtract_node();
				opnode.push(temp);
			}
			else if(token=="*")
			{
				temp=c.build_multiply_node();
				opnode.push(temp);
			}
			else if(token=="/")
			{
				temp=c.build_divide_node();
				opnode.push(temp);
			}
			else //token=="%"
			{
				temp=c.build_modulus_node();
				opnode.push(temp);
			}
		}
	}
	while(operands.size()!=1)
	{
		size_t t1=opnode.size();
		size_t t2=numnode.size();
		if(t2>t1) //number of number nodes more than number of operand nodes
		{
			
			Expr_Node * temp2=opnode.top();
			rightnumber=numnode.top();
			numnode.pop();
			leftnumber=numnode.top();
			//this next line here causes segfault, can not figure out why, since
			//it is just an node using another node to set the child
			temp2->set_children(leftnumber, rightnumber);
			opnode.pop();
			numnode.pop();
			operands.pop();
			tree_=temp2;
		}
		else
		{
			Expr_Node* temp2=opnode.top();
			leftnumber=numnode.top();
			//this next line here causes segfault, can not figure out why, since
			//it is just an node using another node to set the child
			temp2->set_children(leftnumber, tree_);
			tree_=temp2;
			opnode.pop();
			numnode.pop();
			operands.pop();
		}
	}
	return true;
}