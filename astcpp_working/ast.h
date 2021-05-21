#include<iostream>
class BinaryASTnode;
class TernaryASTnode;
class IntLitASTnode;

class ASTnode {
     public :
     virtual ~ASTnode()
     {
     }

     virtual void printPostFix() const = 0;
     virtual void printPreFix() const = 0;
     virtual int evaluate() const = 0;
};

class BinaryASTnode : public ASTnode {
     std::string bin_operator;  

// lhs and rhs can be of any type. 
// So we need to use BaseAST
     ASTnode  *lhs;
     ASTnode *rhs;  

     public:

// Constructor to initialize binary operator, 
// lhs and rhs of the binary expression.
     BinaryASTnode (std::string op, ASTnode* _lhs, ASTnode* _rhs ) :
     bin_operator(op), lhs(_lhs), rhs(_rhs) {}  

     virtual void printPostFix() const 
     {
     	lhs->printPostFix();
     	rhs->printPostFix();
     	std::cout << bin_operator << " ";
     }

     virtual void printPreFix() const 
     {
     	std::cout << bin_operator << " "; 
     	lhs->printPreFix();
     	rhs->printPreFix();
     }

     int evaluate() const
     {
          int res;
          if(bin_operator == "-")
          {
               res = lhs->evaluate() - rhs->evaluate();
          }
          
          if(bin_operator == "+")
          {
               res = lhs->evaluate() + rhs->evaluate();
          }

          if(bin_operator == "*")
          {
               res = lhs->evaluate() * rhs->evaluate();
          }

          if(bin_operator == "/")
          {
               res = lhs->evaluate() / rhs->evaluate();
          }

          return res;

     }

};

class TernaryASTnode : public ASTnode {

     ASTnode  *first;
     ASTnode *second;
     ASTnode *third;  

     public:

     TernaryASTnode (ASTnode *first, ASTnode *second, ASTnode *third ) :
     first(first), second(second), third(third) {}

     virtual void printPostFix() const
     {
     	first->printPostFix();
     	second->printPostFix();
     	third->printPostFix();
     	std::cout << "? " << std::endl; 
     }

     virtual void printPreFix() const
     {
     	std::cout << "? "; 
     	first->printPreFix();
     	second->printPreFix();
     	third->printPreFix();
     }

     int evaluate() const
     {
          int res;
          if(first->evaluate() == 0)
          {
               res = third->evaluate();
          }
          
          else
          {
               res = second->evaluate();
          }
          return res;
     }
};

class IntLitASTnode: public ASTnode {

	int intlit;

	public:

	IntLitASTnode(int intlit): 
	intlit(intlit){}

     virtual void printPostFix() const
	{
		std::cout << intlit << " " ;
	}
     virtual void printPreFix() const
	{
		std::cout << intlit << " " ;
	}

     int evaluate() const
     {
          return intlit;
     }
};

class ASTContext {
public:
    ASTnode *root;

    ~ASTContext()
    {
	    clearAST();
    }

    /// free all saved expression trees
    void	clearAST()
    {
        delete root;
    }
};
