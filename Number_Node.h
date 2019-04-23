#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Expr_Node.h"

class Number_Node : public Expr_Node {
public:
	//Default constructor
	Number_Node (void);
	
	//Node with value
	Number_Node (int num);
	
	//return value
	virtual int eval (void);
	
	//Accept visitor
	virtual void accept (Expr_Node_Visitor * v);
	
	//Destructor
	~Number_Node (void);
	
	 void set_children (Expr_Node * l, Expr_Node * r);
	
private:
	//value
	int value;
	
};

#endif