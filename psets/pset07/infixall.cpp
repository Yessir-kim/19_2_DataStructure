//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//Signed: 김영빈 Section: pset07 Student Number: 21600108

// infix.cpp :
//
// The program evaluates a given infix expression which is fully parenthesized.
// It uses Dijkstra��s two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized.
// For example: ((3 - 1 ) * 5) + 4, 2 * ((34 - 4) * 2), 1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com
// 2019.09.20	Creation
//
#include <iostream>
#include <stack>
#include <cmath>
#include <typeinfo>

using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif



// Stay tuned since we are going to use C++ Template to make them into
// one or a generic function.
// prints stack items from botton to top recursively.

template <class T>
void printStack(T s){
	T t_stack;
	if (!s.empty())
	{
		t_stack.push(s.top()); s.pop();
		printStack(s);
	}
	while(!s.empty())
	{
		temp.push(s.top()); s.pop();
	}

	while(!t_stack.empty())
	{
		s.push(t_stack.top());
		cout << t_stack.top() << " ";
		t_stack.pop();
	}
};

/*void printStack(stack<int>& s) {

	if (!s.empty())
	{
		int temp = s.top(); s.pop();
		t_stack.push(temp);
		printStack(s);
	}

	while(!t_stack.empty())
	{
		int temp = t_stack.top(); t_stack.pop();
		s.push(temp);
		cout << "\nstack<int>: "<< temp << endl;
	}

}*/

/*void printStack(stack<char> s) {
	if (!s.empty())
	{
		int temp = s.top(); s.pop();
		t_stack.push(temp);
		printStack(s);
	}

	while (!t_stack.empty())
	{
		char temp = t_stack.top(); t_stack.pop();
		s.push(temp);
		cout << "\nstack<char>: " << temp << endl;
	}
}*/

// performs arithmetic operations.
int apply_op(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a,b);
	}
	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
}

int compute(stack<int>& va_stack, stack<char>& op_stack) {
	int rigt = va_stack.top(); va_stack.pop();     // right operand first
	int left = va_stack.top(); va_stack.pop();
	char op = op_stack.top(); op_stack.pop();
	int ans = apply_op(left, rigt, op);
	DPRINT(cout << " va/op_stack.pop: " << left << op << rigt << " = " << ans << endl;);
	return ans;
}

int precedence(char thisop, char top){
	char op[] = {'^','*','/','+','-'};
	if(top == op[0])
		return 0;
	else if(top == op[1] || top == op[2])
	{
		if(thisop != op[0])
			return 1;
		else
			return 0;
	}
	else
	{
		if(thisop != op[0] && thisop != op[1] && thisop != op[2])
			return 1;
		else
			return 0;
	}
}

// returns value of expression after evaluation.
int evaluate(string tokens) {
	DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
	stack<int>  va_stack;                 // stack to store operands or values
	stack<char> op_stack;                 // stack to store operators.

	for (int i = 0; i < tokens.length(); i++) {
		DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

		// current token is a whitespace or an opening brace, skip it.
		if (tokens[i] == ' ') continue;
		// if (tokens[i] == '(') continue;

		// current token is a value(or operand), push it to va_stack.
		if (isdigit(tokens[i])) {
			int va = 0;
			int check = i;
			// add the code to handle multi-digits value(operand)
			va = tokens[i] - '0';
			while(isdigit(tokens[++check])){
				va = va * 10 + (tokens[check] - '0');
				i += 1;
			}
			va_stack.push(va);
			DPRINT(cout << " va_stack.push: " << va << endl;);
		} // closing brace encountered; compute it and push the result to va_stack.
		else if (tokens[i] == ')') {
			while(op_stack.top() != '(')
			{
				int answer = compute(va_stack, op_stack);
				va_stack.push(answer);
				DPRINT(cout << " va_stack.push: " << answer << endl;);
			}
			op_stack.pop();
		}
		else if (tokens[i] == '(')
		{
			op_stack.push(tokens[i]);
		}
		else { // current token is an operator; push it to op_stack.
			while(!op_stack.empty())
			{
				char op = op_stack.top();
				int pre = precedence(tokens[i],op);
				if(pre == 1 && op != '(')
				{
					int answer = compute(va_stack, op_stack);
					va_stack.push(answer);
				}
				else
					break;
			}

			op_stack.push(tokens[i]);
			DPRINT(cout << " op_stack.push: " << tokens[i] << endl;);
		}
	}
/*	cout << "\nstack<int>: ";
	printStack(va_stack);
	cout << "\nstack<char>: ";
	printStack(op_stack);
	cout << endl;
*/
	// DPRINT(cout << " Parsing finished...clear va_stack and op_stack if any." << endl;);
	// The whole expression has been parsed at this point,
	// apply remaining op_stack to remaining va_stack.
	while (!op_stack.empty()) {
		int answer = compute(va_stack, op_stack);
		va_stack.push(answer);
		DPRINT(cout << " va_stack.push: " << answer << endl;);
	}

	// DPRINT(cout << "<evaluate" << endl;);
	// va_stack top contains the result, return it.
	return va_stack.top();
}
