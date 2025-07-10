#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

string postfixToInfix(const string& postfix) {
    stack<string> st;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isOperator(token)) {
            if (st.size() < 2) {
                cerr << "Invalid postfix expression!" << endl;
                return "";
            }
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            string expr = "(" + a + " " + token + " " + b + ")";
            st.push(expr);
        } else {
            st.push(token);  // Multi-digit operand or variable
        }
    }

    if (st.size() != 1) {
        cerr << "Invalid postfix expression!" << endl;
        return "";
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter Postfix expression (space-separated, e.g., '12 3 + 4 *'): ";
    getline(cin, postfix);

    string infix = postfixToInfix(postfix);
    if (!infix.empty()) {
        cout << "Infix expression: " << infix << endl;
    }

    return 0;
}


//  Example Input:

// 12 3 + 4 *

//  Output:

// Infix expression: ((12 + 3) * 4)

