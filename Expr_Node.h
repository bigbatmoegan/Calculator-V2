#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

class Expr_Node_Visitor;


class Expr_Node {
public: 
	//Default constructor
	Expr_Node (void);
	
	//Used to transverse the tree
	virtual int eval (void) =0;
	
	//Accept visitor
	virtual void accept (Expr_Node_Visitor * v)=0;
	//Destructor
	virtual ~Expr_Node (void);
	
	//Set chidren
	virtual void set_children (Expr_Node * l, Expr_Node * r)=0;
	
};

#endif