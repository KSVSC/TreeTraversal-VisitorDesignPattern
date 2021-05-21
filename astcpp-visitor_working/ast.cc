// $Id$

#include <iostream>
#include <fstream>
#include "ast.h"
#include "driver.h"
#include "PostFixVisitor.h"
#include "PreFixVisitor.h"
#include "Evaluate.h"

int main(int argc, char *argv[])
{
    ASTContext ast;
    decaf::Driver driver(ast);
    PostFixVisitor pfv;
    PreFixVisitor pfv1;
    Evaluate ev;

    std::string line;
    while( std::cout << "input: " &&
	   std::getline(std::cin, line) &&
	   !line.empty() )
    {
	    
	    bool result = driver.parse_string(line, "input");

	    if (result)
    	{
            if (ast.root != NULL ) {
                std::cout<<"Successfully Parsed!"<<std::endl;
                /*Code*/
                BinaryASTnode *bnode;
                TernaryASTnode *tnode;
                IntLitASTnode *inode;

                std::cout << "Postfix Form: " << std::endl; 

                bnode = dynamic_cast<BinaryASTnode *>(ast.root);
                if (bnode != NULL)
                    pfv.visit(*bnode);

                tnode = dynamic_cast<TernaryASTnode *>(ast.root);
                if (tnode != NULL)
                    pfv.visit(*tnode);

                inode = dynamic_cast<IntLitASTnode *>(ast.root);
                if (inode != NULL)
                    pfv.visit(*inode);
                
                 std::cout <<  std::endl;

                std::cout << "Prefix Form: " << std::endl; 

                if (bnode != NULL)
                    pfv1.visit(*bnode);

                if (tnode != NULL)
                    pfv1.visit(*tnode);

                if (inode != NULL)
                    pfv1.visit(*inode);
                
                 std::cout <<  std::endl;

                std::cout << "Evaluation: " << std::endl; 

                int ans;
                bnode = dynamic_cast<BinaryASTnode *>(ast.root);
                if (bnode != NULL)
                    ans = ev.solve(*bnode);

                tnode = dynamic_cast<TernaryASTnode *>(ast.root);
                if (tnode != NULL)
                    ans = ev.solve(*tnode);

                inode = dynamic_cast<IntLitASTnode *>(ast.root);
                if (inode != NULL)
                    ans = ev.solve(*inode);
                
                 std::cout << ans<<std::endl;
            }
            ast.clearAST();
	    }
	}
}

