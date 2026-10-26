
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;


// Returns the precedence of an operator
int preced(char ch) {
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;

    return 0;
}


// Part (a): Convert infix to postfix
string to_postf(string str) {

    stack<char> stk;
    string postf = "";

    for (char c : str) {

        // Ignore spaces
        if (isspace(c)) {
            continue;
        }

        // Operand: add directly to postfix
        if (isdigit(c)) {
            postf += c;
        }

        // Opening parenthesis: push onto stack
        else if (c == '(') {
            stk.push(c);
        }

        // Closing parenthesis: pop until '('
        else if (c == ')') {

            while (!stk.empty() && stk.top() != '(') {
                postf += stk.top();
                stk.pop();
            }

            if (!stk.empty()) {
                stk.pop();
            }
        }

        // Operator: pop operators with higher
        // or equal precedence, then push current operator
        else {

            while (!stk.empty() && stk.top() != '(' &&
                   preced(stk.top()) >= preced(c)) {

                postf += stk.top();
                stk.pop();
            }

            stk.push(c);
        }
    }

    // Pop remaining operators
    while (!stk.empty()) {
        postf += stk.top();
        stk.pop();
    }

    return postf;
}


// Part (b): Evaluate postfix using a second stack
int evaluate(string postf) {

    stack<int> stk;

    for (char c : postf) {

        // If digit, convert character to integer
        // and push it onto the operand stack
        if (isdigit(c)) {
            stk.push(c - '0');
        }

        // Otherwise, process the operator
        else {

            // Pop the second operand first
            int b = stk.top();
            stk.pop();

            // Pop the first operand
            int a = stk.top();
            stk.pop();

            int result;

            if (c == '+') {
                result = a + b;
            }
            else if (c == '-') {
                result = a - b;
            }
            else if (c == '*') {
                result = a * b;
            }
            else if (c == '/') {
                result = a / b;
            }

            // Push the result back onto the stack
            stk.push(result);
        }
    }

    // Final answer remains on top
    return stk.top();
}


int main() {

    string str;

    cout << "Enter infix expression: ";
    getline(cin, str);

    // Convert infix to postfix
    string postf = to_postf(str);

    cout << "Infix: " << str << endl;
    cout << "Postfix: " << postf << endl;

    // Evaluate the postfix expression
    cout << "Result: " << evaluate(postf) << endl;

    return 0;
}
