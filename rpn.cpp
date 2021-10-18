#include "rpn.h"
#include <cmath>
bool isOperator(string op){
    return (op == "+" || op == "-" || op == "*" || op == "/" || op == "**" || op == "<" || op == ">");
}

bool isNum(string s){
    if (s.length() == 1)
        return s[0] >= '0' && s[0] <= '9';
    else if(s.length() > 1 && s[0] == '-'){
        return s[1] >= '0' && s[1] <= '9';
    }
    else if(s.length()>1 && s[0] >= '0' && s[0] <= '9'){
        return true;
    }
    return false;
}

double scanNum(string s){
    return stof(s);
}

double performCalc(float num1, float num2, string op){
    if(op == "+"){
        return (num1+num2);
   }
   else if (op == "-"){
       return num1 - num2;
   }
   else if (op == "*"){
       return num1 * num2;
   }
   else if (op == "/"){
       if (num2 == 0){
           cout<<"Division by zero\n";
            exit(EXIT_FAILURE);
       }
       return num1/num2;
   }
   else if (op == "**"){
       if(num1 == 0 && num2 == 0){
           cout << "Invalid Operation"<< endl;
           exit(EXIT_FAILURE);
       }
       return pow(num1,num2);
   }
   else if(op == "<"){
       return floor(num1);
   }
   else if(op == ">"){
       return ceil(num1);
   }
   else{
       cout<<"Operator not recognized";
       return 0;
   }
}

/* Convert the array of strings into a binary tree for easy printing */
Node* constructTree(string* strs, int n){
    stack<Node*>tree;
    Node *left, *right;
    for(int i = 0; i < n; i++){
        if(isOperator(strs[i])){
            if(strs[i] != "<" && strs[i] != ">"){
                right = tree.top();
                tree.pop();
            }
            left = tree.top();
            tree.pop();
            //Pop the 2 numbers from the stack and push the result of the calc
            Node *node;
            if(strs[i] == "<" || strs[i] == ">"){
                node = new Node(left, nullptr, strs[i]); 
            } else{
                node = new Node(left, right, strs[i]);
            }
            tree.push(node);
        } else if(isNum(strs[i])){
			//Push the numbers until we see an operator
			tree.push(new Node(strs[i]));
		}
   
    }
    return tree.top();
}

/* Prints the output for Part 2 */
void printOrder(Node* root, int layer = 0){
    if(root != nullptr){
        if(isOperator(root->data)){
            for(int i = 0; i < layer; i++){
                cout << "\t";
            }
            cout << "(" << root->data << endl;   
        } else if(isNum(root->data)){
        
            for(int i = 0; i < layer; i++){
                cout << "\t";
            }
            cout << root->data << endl;
               
        }

        if(root->data == "<" || root->data == ">"){
            printOrder(root->left,layer+1);
            for(int i = 0; i < layer; i++){
                cout << "\t";
            }
            cout << ")" << endl;
        }
        else{
           printOrder(root->left,layer+1); 
        }
        
        if(root->right){
            printOrder(root->right,layer+1);
            for(int i = 0; i < layer; i++){
                cout << "\t";
            }
            cout << ")" << endl;
        }
    }
    
    if(root == nullptr){
        return;
    }
}

int main(int argc, char* argv[]){
    if(argc == 2)
        flag = true;
    // Incorrect order of operands
    //string test1[] = {"2", "+","12"}; 
    //int n1 = 3;
    //Normal test. Output: 2.66667
    string test2[] = {"2","12","6","-","/","5","3","+","*"};
    int n2 = 9;
    //Division by zero
    //  string test3[] = {"2","6","6","-","/","5","3","+","*"};
    //  int n3 = 9;
    //Too many operands and no operators given
    //  string test4[] = {"2","12"}; 
    //  int n4 = 2;
    //Floats and negative numbers. Normal
    //  string test5[] = {"2.0","12.6","-5.3","-","**","-5.7","3.9","+","*"};
    //  int n5 = 9;
    //Floor and ceil
    //  string test6[] = {"9.5", "<", "10.2",">", "+"};
    //  int n6 = 5;

    //double result1 = rpn(test1,n1);
    double result2 = rpn(test2,n2); 
    //double result3 = rpn(test3,n3);
    //double result4 = rpn(test4,n4);
    //double result5 = rpn(test5,n5);
    //double result6 = rpn(test6,n6); 
    if(!flag){
      //  cout << result1 << endl;
        cout << result2 << endl;
        //cout << result3 << endl;
        //cout << result4 << endl;
        //cout << result5 << endl;
        //cout << result6 << endl;

    }
    return 0;
}