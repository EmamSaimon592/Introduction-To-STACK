#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

string infixToPostfix(const string& infix) {
    stack<string> opStack;
    vector<string> output;
    stringstream ss(infix);
    string token;

    while (ss >> token) {
        if (token == "(") {
            opStack.push(token);
        }
        else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();  // Pop '('
        }
        else if (isOperator(token)) {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(token)) {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
        else {
            output.push_back(token);  // Operand
        }
    }

    while (!opStack.empty()) {
        output.push_back(opStack.top());
        opStack.pop();
    }

    // Combine output into a space-separated string
    string result;
    for (const string& tok : output) {
        result += tok + " ";
    }
    return result;
}

int main() {
    string infix;
    cout << "Enter Infix expression (space-separated, e.g., ( 12 + 3 ) * 4 ): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}


// Sample Input:

// ( 12 + 3 ) * 4

//  Output:

// Postfix expression: 12 3 + 4 *