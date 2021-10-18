#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
bool flag = false;
bool isRightChild = false;
struct Node{
	string data;
	Node* left, *right;

	Node(Node* left, Node* right, string data){
		this->data = data;
		this->left = left;
		this->right = right;
	}

	Node(string data){
		this->data = data;
	}
};

bool isOperator(string op);
bool isNum(string s);
double scanNum(string s);
double performCalc(float num1, float num2, string op);
void printOrder(Node* tree, int layer);
Node* constructTree(string *strs, int n);
double rpn(string *strs, int n) 
{
	double result = 0.0;
	double num1, num2;
	double res;
	stack<double> nums;
	if(!flag){
	for(int i = 0; i < n; i++){
	// If operator is seen, we need to store the most recent 2 nums and perform
	// a calculation using the operator just seen. 
		if(!isOperator(strs[i]) && !isNum(strs[i])){
			cout<<"Input is neither a number nor an operator\n";
			exit(EXIT_FAILURE);
		}
		if(isOperator(strs[i])){
			if(nums.empty()){
				cout<<"Need more operands before the operator" << endl;
				exit(EXIT_FAILURE);
			}
			num2 = nums.top();
			nums.pop();
			if(nums.empty()){
				cout << "Need more operands before the operator\n";
				exit(EXIT_FAILURE);
			}
			num1 = nums.top();
			nums.pop();
			//Pop the 2 numbers from the stack and push the result of the calc
			res = performCalc(num1,num2,strs[i]);
			nums.push(res);
		} else if(isNum(strs[i])){
			//Push the numbers until we see an operator
			nums.push(scanNum(strs[i]));
		}
	}
	result = nums.top();
	if (nums.size() > 1){
		cout << "Too many operands or operators given"<< endl;
		exit(EXIT_FAILURE);
	}
	return result;
	}
	else if(flag){
		Node *tree = constructTree(strs,n);
		printOrder(tree,0);
	}
	return 0;
}