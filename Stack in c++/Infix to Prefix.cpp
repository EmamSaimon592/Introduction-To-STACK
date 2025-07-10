#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
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

// Function to reverse and swap parentheses
string reverseAndSwapParentheses(const string& expr) {
    string rev = expr;
    reverse(rev.begin(), rev.end());
    for (char& ch : rev) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    return rev;
}

string infixToPrefix(const string& infix) {
    string expr = reverseAndSwapParentheses(infix);
    stack<char> opStack;
    string result;

    for (char ch : expr) {
        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            opStack.push(ch);
        }
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                result += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // pop '('
        }
        else if (isOperator(ch)) {
            result += ' ';
            while (!opStack.empty() && precedence(opStack.top()) > precedence(ch)) {
                result += opStack.top();
                result += ' ';
                opStack.pop();
            }
            opStack.push(ch);
        }
    }

    while (!opStack.empty()) {
        result += opStack.top();
        opStack.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string infix;
    cout << "Enter infix expression (e.g., (A+B)*C): ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}


/* Example Input:

(A + B) * C

Output:

Prefix expression: *+ABC

 Logic Summary:

    Reverse the infix expression.

    Swap ( with ) and vice versa.

    Convert to Postfix.

    Reverse the result to get Prefix.
*/