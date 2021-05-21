// $Id$

#include <iostream>
#include <fstream>

#include "driver.h"
#include "ast.h"

int main(int argc, char *argv[])
{
    ASTContext ast;
    decaf::Driver driver(ast);
    
    std::string line;
    while( std::cout << "input: " &&
	   std::getline(std::cin, line) &&
	   !line.empty() )
    {
	    
	    bool result = driver.parse_string(line, "input");

	    if (result)
    	{
            std::cout<<"Successfully Parsed!"<<std::endl;
            if (ast.root != NULL ) {
                 /*Code*/
                std::cout << "Postfix Form: " << std::endl; 
                ast.root->printPostFix();
                std::cout <<  std::endl; 

                std::cout << "Prefix Form: " << std::endl; 
                ast.root->printPreFix();
                std::cout <<  std::endl;

                std::cout << "Evaluation: " << std::endl; 
                int result = ast.root->evaluate();
                std::cout <<  result << std::endl;
            }
            ast.clearAST();
	    }
	}
}

