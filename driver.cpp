#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Number_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiplication_Expr_Node.h"
#include "Division_Expr_Node.h"
#include "Modulus_Expr_Node.h"
#include "Expr_Node_Visitor.h"
#include "Eval_Expr_Tree.h"
#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>

int main (int argc, char * argv [])
{
	bool keepGoing=true;
	while(keepGoing)
	{
		std::string expression="";
		std::cout << "Enter an Expression: ";
		std::getline(std::cin, expression);
		if(expression=="QUIT")
		{
			return 0;
			
		}
		else
		{
			Expr_Builder *b=new Expr_Tree_Builder;
			b->parse_expr(expression);
			Expr_Node * expr=b->get_expression();
			Eval_Expr_Tree *eval=new Eval_Expr_Tree;
			expr->accept(eval);
			int result=expr->eval();
			std::cout << result << std::endl;
			//delete expr;
			//delete b;
			//delete eval;
		}
	}
	/*
	Expr_Node * n1=new Number_Node (5);
	Expr_Node * n2=new Number_Node (4);
	Expr_Node * n3=new Number_Node (3);
	Expr_Node * expr=new Add_Expr_Node (n1, n2);
	expr->set_children(n1, n3);
	int result=expr->eval();
	std::cout << result << std::endl;
	delete expr;
	return 0;
	*/
}

	//Left the following code in to show that each of the nodes
	//Works as intended, as well as the visitor. However, one line
	//in the builder is causing a segfault, and have marked it, can
	//not figure out why it is.
	
	
	
	/*5 + 4
	Expr_Node * n1=new Number_Node (5);
	Expr_Node * n2=new Number_Node (4);
	Expr_Node * expr=new Add_Expr_Node (n1, n2);
	int result=expr->eval();
	std::cout << result << std::endl;
	delete expr;
	//5 - 4
	Expr_Node * n3=new Number_Node (5);
	Expr_Node * n4=new Number_Node (4);
	Expr_Node * expr2=new Subtract_Expr_Node (n3, n4);
	int result2=expr2->eval();
	std::cout << result2 << std::endl;
	// 5 * 4
	Expr_Node * n5=new Number_Node (5);
	Expr_Node * n6=new Number_Node (4);
	Expr_Node * expr3=new Multiplication_Expr_Node(n5, n6);
	int result3=expr3->eval();
	std::cout << result3 << std::endl;
	// 10 / 5
	Expr_Node * n7=new Number_Node (10);
	Expr_Node * n8=new Number_Node (5);
	Expr_Node * expr4=new Division_Expr_Node (n7, n8);
	int result4=expr4->eval();
	std::cout << result4 << std::endl;
	delete expr2;
	delete expr3;
	delete expr4;
	// 5 + 4 - 8
	Expr_Node * n9=new Number_Node (5);
	Expr_Node *n10=new Number_Node (4);
	Expr_Node *n11=new Number_Node (8);
	Expr_Node *expr5=new Add_Expr_Node(n9, n10);
	Expr_Node *expr6=new Subtract_Expr_Node (expr5, n11);
	int result5=expr6->eval();
	std::cout << result5 << std::endl;
	Eval_Expr_Tree *eval=new Eval_Expr_Tree;
	expr6->accept(eval);
	int result6=eval->result();
	std::cout << result6 << std::endl;
	
}

	*/