/*

Created by Victor Gutierrez
on 4/25/17

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Tree.hpp"

using namespace std;

void help(char const *ag){
        printf("\ninterpreter - interprets LISP code\n");
        printf("Please read the README for more information\n");
        printf("Usage: %s\n", ag);
        printf("\n-h displays this help menu\n\n");
}

int main(int argc, char const *argv[]) {
        string input;
        Tree tree;

        if (argc > 1) {
            help(argv[0]);
            return 0;
        }

        cout << "\nWelcome to the fancy new Prompt LISP INTERPRETER, type in lisp command!\n";
        cout << "Type (quit) to exit the program\n\n";

        while(input != "(quit)") {
                cout << "Prompt> ";
                getline(cin, input);
                tree.tokenTree(input);
        }

        return 0;
}
