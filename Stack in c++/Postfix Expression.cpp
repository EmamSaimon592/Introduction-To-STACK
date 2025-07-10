#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int applyOperation(int a, int b, const string& op) {
    if (op == "+") return a + b;
    else if (op == "-") return a - b;
    else if (op == "*") return a * b;
    else if (op == "/") return a / b;
    return 0;
}

int evaluateRPN(const string& expression) {
    stack<int> st;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isOperator(token)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = applyOperation(a, b, token);
            st.push(result);
        } else {
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main() {
    string expression;
    cout << "Enter RPN expression (e.g., '5 3 + 8 2 - *'): ";
    getline(cin, expression);

    int result = evaluateRPN(expression);
    cout << "Result: " << result << endl;

    return 0;
}

// Example Input:

// 5 3 + 8 2 - *

//  Output:

// Result: 48