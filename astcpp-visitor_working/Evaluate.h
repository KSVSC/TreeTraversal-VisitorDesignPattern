class Evaluate: public ASTvisitor {
    /*Complete the class*/
    public:

    virtual int solve(BinaryASTnode& node)
    {
        int res;
        int left = node.getLeft()->eval(*this);
        int right = node.getRight()->eval(*this);
        if(node.getBin_operator() == "-")
        {
            res = left - right;
        }
        
        if(node.getBin_operator() == "+")
        {
            res = left + right;
        }

        if(node.getBin_operator() == "*")
        {
            res = left * right;
        }

        if(node.getBin_operator() == "/")
        {
            res = left / right;
        }

        return res;
    }

    virtual int solve(TernaryASTnode& node)
    {
        int res=0;
        int second = node.getSecond()->eval(*this);
        int third = node.getThird()->eval(*this);
        if(node.getFirst()->eval(*this) == 0)
        {
            res = second;
        }
        else
        {
            res = third;
        }

        return res;
    }

    virtual int solve(IntLitASTnode& node)
    {
        return node.getIntLit();
    }
};