# LISP Interpreter
Simple LISP interpreter written in C++. Done during my sophomore
year at NMT.
The project executes LISP style commands from a prompt all while
within a C++ environment. The program parses and execute lisp
code  as outlined in the section below named # LISP commands.
The program functions like an interactive LISP interpreter and
outputs intermediate results to the terminal.

# Usage
First run make in the terminal.
After making the program run the following command:

    $ ./interpreter

After running that command you should see the following:

    Welcome to the fancy new Prompt LISP INTERPRETER, type
    in a lisp command!
    Type (quit) to exit the program

    Prompt>

To exit the program enter

    Prompt> (quit)

# LISP commands

Expression            Syntax                   Semantics
--------------------------------------------------------------------
Variable Reference | (var)                  | A variable name.
Constant literal   | (number)               | A number evaluates to
                   |                        | to itself.
Quotation          | (quote exp)            | Returns exp without
                   |                        | evaluating it.
Conditional        | (if test conseq alt)   | Evaluates test; if true,
                   |                        | it evaluates and returns
                   |                        | conseq; otherwise alt.
Definition         | (define var exp)       | Defines a new variable
                   |                        | and assignes it exp
Assignment         | (set! var exp)         | Sets var to exp
Procedure          | (lambda (var...) exp)  | Creates a procedure with
                   |                        | parameters (var...) and
                   |                        | exp as the body.

# Example of execution
The following is an example of execution flow:

    $ ./interpreter

    Welcome to the fancy new Prompt LISP INTERPRETER, type in a lisp command!
    Type (quit) to exit the program

    Prompt> (define var1 5)
        var1 = 5
    Prompt> (define var2 10)
        var2 = 10
    Prompt> (* var2 var1)
        50
    Prompt> (quote (This is a quote))
        (This is a quote)
    Prompt> (if (> var1 var2)(+ 1 2)(+ 3 3))
        6
    Prompt> (set! var1 11)
        var1 = 11
    Prompt> (if (> var1 var2)(+ 1 2)(+ 3 3))
        3
    Prompt> (lambda add3 (var)(+ 3 var))   
        add3 saved!
    Prompt> add3(4)
        7
    Prompt> (quit)
