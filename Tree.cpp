/*

Created by Victor Gutierrez
on 4/25/17

*/
#include "Tree.hpp"
#include <iostream>
#include <string>

void Tree::tokenTree(string input) {
        int charPos = 0;
        string buffer;
        vector <string> tokenVec;

        if (input == "(quit)") {
                return;
        }

        while (charPos < input.length()) {
                if (input[charPos] == '(' && !buffer.empty()) {
                        //adding the token to the vector
                        tokenVec.push_back(buffer);
                        buffer.clear();
                }

                if (input[charPos] == ')' && !buffer.empty()) {
                        tokenVec.push_back(buffer);
                        //node.token = buffer;
                        buffer.clear();
                }

                if (input[charPos] != ' ' && input[charPos] != '(' && input[charPos] != ')') {
                        buffer.push_back(input[charPos]);
                }

                if (input[charPos] == ' ' && input[charPos - 1] != ')' && !buffer.empty()) {
                        tokenVec.push_back(buffer);
                        //node.token = buffer;
                        buffer.clear();
                }
                charPos++;
        }

        check(tokenVec);
}

/*checks what operation is being done and executes*/
double Tree::execOperation(string operation, double a, double b) {
        double c = 0;
        if (operation == "+") {
                c = a + b;
        }
        else if (operation == "-") {
                c = a - b;
        }
        else if (operation == "*") {
                c = a * b;
        }
        else if (operation == "/") {
                c = a / b;
        }
        else {
                cout << "Please enter a valid operation (+, -, *, /)" << endl;
        }
        return c;
}

/*Prints out the list after "quote"*/
void Tree::printQuote(vector<string> quoteVec) {
        cout << "(";
        for (size_t i = 1; i < quoteVec.size(); i++) {
                cout << quoteVec[i];
                if (i != quoteVec.size()-1) {
                        cout << " ";
                }
        }
        printf (")\n");
}

/*executes an if statement*/
void Tree::ifStatement(vector<string>ifVec, int bookmark){
        double a, b, c;
        size_t optrueA, optrueB;
        size_t opfalseA, opfalseB;

        /*checking to see if the comparing digits are variables*/
        a = stringVarConversion(ifVec[bookmark + 1]);
        b = stringVarConversion(ifVec[bookmark + 2]);

        /*checking to see if the operation digits are variables*/
        //if True
        optrueA = stringVarConversion(ifVec[bookmark + 4]);
        optrueB = stringVarConversion(ifVec[bookmark + 5]);

        //if False
        opfalseA = stringVarConversion(ifVec[bookmark + 7]);
        opfalseB = stringVarConversion(ifVec[bookmark + 8]);

        /*Checking the comparison being done*/
        if (ifVec[bookmark] == "<") {
                if(a < b) {
                        /*call execOperation
                          on the first part of the if statement*/
                         c = execOperation(ifVec[bookmark + 3], optrueA, optrueB);
                         cout << c <<endl;

                } else {
                        /*call execOperation
                          on the second part of the if statement*/
                         c = execOperation(ifVec[bookmark + 6], opfalseA, opfalseB);
                         cout << c <<endl;
                }

        }
        else if (ifVec[bookmark] == ">") {
                if (a > b) {
                        /*call execOperation
                          on the first part of the if statement*/
                          c = execOperation(ifVec[bookmark + 3], optrueA, optrueB);
                          cout << c <<endl;
                } else {
                        /*call execOperation
                          on the second part of the if statement
                          and so on, on the rest of comparisons*/
                          c = execOperation(ifVec[bookmark + 6], opfalseA, opfalseB);
                          cout << c <<endl;
                }

        }
        else if (ifVec[bookmark] == "==") {
                if (a == b) {
                        c = execOperation(ifVec[bookmark + 3], optrueA, optrueB);
                        cout << c <<endl;
                }else {
                        c = execOperation(ifVec[bookmark + 6], opfalseA, opfalseB);
                        cout << c <<endl;
                }

        }
        else if (ifVec[bookmark] == "<=") {
                if (a <= b) {
                        c = execOperation(ifVec[bookmark + 3], optrueA, optrueB);
                        cout << c <<endl;
                }else {
                        c = execOperation(ifVec[bookmark + 6], opfalseA, opfalseB);
                        cout << c <<endl;
                }

        }
        else if (ifVec[bookmark] == ">=") {
                if (a >= b) {
                        c = execOperation(ifVec[bookmark + 3], optrueA, optrueB);
                        cout << c <<endl;
                } else {
                        c = execOperation(ifVec[bookmark + 6], opfalseA, opfalseB);
                        cout << c <<endl;
                }

        }
        else if (ifVec[bookmark] == "!=") {
                if (a != b){
                        c = execOperation(ifVec[bookmark + 3], optrueA, optrueB);
                        cout << c <<endl;
                } else {
                        c = execOperation(ifVec[bookmark + 6], opfalseA, opfalseB);
                        cout << c <<endl;
                }
        }
}

bool Tree::checkOperation(string operation){
        if (operation == "+" || operation == "-") {
                return true;
        } else if (operation == "*" || operation == "/") {
                return true;
        } else {
                return false;
        }
}

/*works for regular operations*/
double Tree::nestedOperation(vector<string> optVec) {
        string opt = optVec[0];
        double c = 0;
        double a, b;

        if (checkOperation(optVec[1])) {
                optVec.erase(optVec.begin());
                b = stringVarConversion(optVec[optVec.size()]);
                optVec.pop_back();
                a = nestedOperation(optVec);
                c = execOperation(opt, a, b);
        } else {
                a = stringVarConversion(optVec[1]);
                b = stringVarConversion(optVec[2]);
                c = execOperation(opt, a, b);
        }
        return c;
}

/*works for lamda operations*/
double Tree::lamdaOperations(vector<string> optVec) {
        string opt = optVec[0];
        double c = 0;
        double a, b;

        if (checkOperation(optVec[1])) {
                optVec.erase(optVec.begin());
                b = stringArgConversion(optVec[optVec.size()]);
                optVec.pop_back();
                a = lamdaOperations(optVec);
                c = execOperation(opt, a, b);
        } else {
                a = stringArgConversion(optVec[1]);
                b = stringArgConversion(optVec[2]);
                c = execOperation(opt, a, b);
        }
        return c;
}

/*checks if the var passed is saved in the var map*/
double Tree::stringVarConversion(string var) {
        double result;

        if (this->variables.find(var) == this->variables.end()) {
            try{
                result = stoi(var);
            } catch (exception& e){
                cout << "Caught exception " << e.what() << endl;
            }
        } else {
            try{
                result = stoi(this->variables[var]);
            } catch (exception& e){
                cout << "Caught exception " << e.what() << endl;
            }
        }
        return result;
}

/*checks if the var passed is seved in the Args map*/
double Tree::stringArgConversion(string var) {
        double result = 0;

        if (this->lamArgs.find(var) == this->lamArgs.end()) {
            try{
                result = stoi(var);
            } catch (exception& e){
                cout << "Caught exception " << e.what() << endl;
            }
        } else {
            try{
                result = stoi(this->lamArgs[var]);
            } catch (exception& e){
                cout << "Caught exception " << e.what() << endl;
            }
        }
        return result;
}

/*gets called when the user wants to execute cos*/
void Tree::callCos(double n) {
    cout << cos(n) << endl;
}

/*gets called when the user wants to execute sin*/
void Tree::callSin(double n) {
    cout << sin(n) << endl;
}

/*gets called when the user wants to execute tan*/
void Tree::callTan(double n) {
    cout << tan(n) << endl;
}

/*gets called when the user wants to execute square*/
void Tree::square(double n){
        n = n * n;
        cout << n << endl;
}

void Tree::check(vector<string> bufferVec) {
        double temp;
        string lamTemp;
        vector<string> function;

        while(!bufferVec.empty()) {
                if (bufferVec[0] == "quote") {
                        printQuote(bufferVec);
                        bufferVec.erase(bufferVec.begin(), bufferVec.end());
                }
                else if (bufferVec[0] == "if") {
                        ifStatement(bufferVec, 1);
                        bufferVec.erase(bufferVec.begin(), bufferVec.begin()+9);
                }
                else if (bufferVec[0] == "define") {
                        this->variables[bufferVec[1]] = bufferVec[2];
                        cout << bufferVec[1] << " = " << bufferVec[2] << endl;
                        bufferVec.erase(bufferVec.begin(), bufferVec.begin() + 3);

                }
                else if (bufferVec[0] == "set!") {
                        this->variables[bufferVec[1]] = bufferVec[2];
                        cout << bufferVec[1]<< " = "<< this->variables.begin()->second<<endl;
                        bufferVec.erase(bufferVec.begin(), bufferVec.begin() + 3);
                }
                else if (checkOperation(bufferVec[0]) == true) {
                        temp = nestedOperation(bufferVec);
                        bufferVec.erase(bufferVec.begin(), bufferVec.end());
                        cout << temp <<endl;
                }
                else if (bufferVec[0] == "cos") {
                        temp = stringVarConversion(bufferVec[1]);
                        callCos(temp);
                        bufferVec.erase(bufferVec.begin(), bufferVec.end());
                }
                else if (bufferVec[0] == "sin") {
                        temp = stringVarConversion(bufferVec[1]);
                        callSin(temp);
                        bufferVec.erase(bufferVec.begin(), bufferVec.end());
                }
                else if (bufferVec[0] == "tan") {
                        temp = stringVarConversion(bufferVec[1]);
                        callTan(temp);
                        bufferVec.erase(bufferVec.begin(), bufferVec.end());
                }
                else if (bufferVec[0] == "square") {
                        temp = stringVarConversion(bufferVec[1]);
                        square(temp);
                        bufferVec.erase(bufferVec.begin(), bufferVec.end());
                }
                else if (bufferVec[0] == "lambda") {
                        lamTemp = bufferVec[1];
                        bufferVec.erase(bufferVec.begin(), bufferVec.begin() + 2);
                        this->lambdaVars[lamTemp] = bufferVec;
                        cout << lamTemp << " saved!"<< endl;
                        bufferVec.erase(bufferVec.begin(), bufferVec.end());
                }
                else if (this->variables.find(bufferVec[0]) != this->variables.end()) {
                        cout << this->variables[bufferVec[0]] << endl;
                        bufferVec.erase(bufferVec.begin());
                }
                else if (this->lambdaVars.find(bufferVec[0]) != this->lambdaVars.end()) {
                        function = this->lambdaVars[bufferVec[0]];
                        bufferVec.erase(bufferVec.begin());

                        /*saves the arguments in the lamArgs map*/
                        while (!checkOperation(function[0])) {
                                this->lamArgs[function[0]] = bufferVec[0];
                                function.erase(function.begin());
                                bufferVec.erase(bufferVec.begin());
                        }
                        /*UNSURE OF THIS MIGHT BE BUG LATER*/
                        //function.pop_back();

                        temp = lamdaOperations(function);
                        bufferVec.erase(bufferVec.begin(), bufferVec.end());
                        function.erase(function.begin(), function.end());
                        cout << temp <<endl;
                }
                else {
                        bufferVec.erase(bufferVec.begin());
                }

        }
}
