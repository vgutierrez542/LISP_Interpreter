/*

Created by Victor Gutierrez
on 4/25/17

*/

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Tree {
private:
        map<string, string> variables;
        map<string, vector<string> > lambdaVars;
        map<string, string> lamArgs;

        void ifStatement(vector<string>ifVec, int bookmark);
        void printQuote(vector<string> quoteVec);
        double execOperation(string operation, double a, double b);
        bool checkOperation(string operation);
        double stringVarConversion(string var);
        double nestedOperation(vector<string> optVec);
        double lamdaOperations(vector<string> optVec);
        double stringArgConversion(string var);
        void square(double n);
        void callCos(double n);
        void callSin(double n);
        void callTan(double n);

public:
        void tokenTree(string input);
        void check(vector<string> bufferVec);
};
