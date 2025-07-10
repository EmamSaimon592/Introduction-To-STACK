#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string infixToPostfix(const string& infix) {
    stack<char> opStack;
    string postfix;

    for (char ch : infix) {
        if (isspace(ch)) continue;

        // If operand, add to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            opStack.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += ' ';
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Remove '('
        }
        // If operator
        else if (isOperator(ch)) {
            postfix += ' ';
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch)) {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            opStack.push(ch);
        }
    }

    // Pop remaining operators
    while (!opStack.empty()) {
        postfix += ' ';
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression (e.g., (A+B)*C): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}


/* Example Input:

(A + B) * C

 Output:

Postfix expression: A B + C *


 Features:

    Supports basic operators: + - * /

    Handles parentheses

    Ignores spaces

    Works with variables like A, B, x, etc.
*/