# RPN_Calculator

## INTRODUCTION
This project involves a simple implementation of the Reverse Polish Notation(RPN) calculator, sometimes also known as the postfix calculator. The implementation handles a few of the common arithmetic operations, including addition, subtraction, multiplication, division, exponentiation, floor and ceil operators.

## IMPLEMENTATION AND CONSTRAINTS
###1. INPUT
The function behaving like an RPN calculator is the rpn. The parameters that are passed to this function are an array of strings that are the numbers and the operators, and the size of the array. The input to the program has been hardcoded, to generate various test cases, and try to handle different errors and edge cases.


### 2. INTRO TO DIFFERENT FUNCTIONS
The `isNum(string s)`function checks if a string(one of the elements of the array) is a number 
The `isOperator(string op)` function checks if a string is one of the valid operators. 
The `scanNum(string s)` converts the number to a floating point.
The `performCalc(float num1, float num2, string op)` function takes two numbers and an operator and performs the operation.
The `rpn(string *strs, int n)` function is the one that behaves like the RPN calculator, uses all the above functions and returns the appropriate result.
The `constructTree(string *strs, int n)` constructs a binary tree out of the array, for easy printing when the user inputs -l.
The `printOrder(Node* tree)` uses recursive DFS to print the output.


### 3. OPERATOR SUPPORT
As mentioned above, the code is supposed to support the addition(+), subtraction(-), multiplication(*), division(/), exponent(**), floor(<<) and ceil(>>) operators. An operation can be performed on at most 2 operands before the result is pushed on the stack for the next operation, except in case for floor and ceil operations.

### 4. STACK
The stack ADT is one of the most used data structures for this type of problem. This is because we need to work with the most recent entries/numbers we have seen. 


For implementing the calculator, we push numbers to the stack until we see an operator. When we see an operator, we perform a calculation and push the result onto the stack. This carries on until we reach the end of the input array. 


### 5. INVOCATION OF THE PROGRAM
Before the invocation of the program, please take note that multiple test cases cannot be run simultaneously if they produce some error, since, by design, the functions would exit() the program with exit code 1 after printing the error message. To deal with this, look at all the test cases in main, and uncomment the test case that you want to test, while commenting out all the rest. 6 tests are created, and each test gives the functionality it tests. Uncomment the test array, the size, the result of the corresponding number, and the cout statement of the corresponding result. Make sure all the other tests, couts and result definitions are commented out. So for example, for running test1, which looks at order of operators and operands, we uncomment the variable test1, n1, result1 and the cout statement displaying result1. The program invocation takes into account 2 command line arguments, a.out and an optional “-l”. The -l command would print the order of operations, in the operator, num1, num2 order. 


### 6. ERROR MESSAGES
Error handling has been done in this program to handle errors gracefully. Every time there is an invalid operation taking place, the program will print the error message to the user, letting them know what went wrong, and `exit` the program with exit code 1. Some examples of errors handled by the program are division by zero, blank string as an array element,  and invalid operator or operands. The (0^0) operation, although outputs 1 in case of C++, is treated as an invalid operation in this case. 


### 7. THE -l COMMAND
The `-l` command is supposed to print the order of operations in a way that the innermost bracket/parentheses is the most indented, and the indentation reduces as we move outwards. This was done by converting the array into a binary tree using the `constructTree(string *strs, int n)` function and recursive DFS of the tree prints the order of operations.

### 8. TREE AND NODE STRUCT
As mentioned in section 7, a tree has been created to facilitate easy printing when the user input -l. The tree has been constructed using a Node struct, which has pointers to left and right children, and a data variable to hold the value. Inside the struct, we create 2 types of constructors, one that initializes the left and the right children, and the other where the node is a leaf, in which case, only data is initialized.   

### 9. ASSUMPTIONS
Since the input to the rpn function is hardcoded, I assume that always, the right number of operands and operators will be given. Another assumption is that all input will either be strings representing numbers or valid operators.
