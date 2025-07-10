#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
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

int evaluatePrefix(const string& expression) {
    stack<int> st;
    vector<string> tokens;
    stringstream ss(expression);
    string token;

    // Split expression into tokens
    while (ss >> token) {
        tokens.push_back(token);
    }

    // Traverse tokens in reverse order (right to left)
    for (int i = tokens.size() - 1; i >= 0; i--) {
        token = tokens[i];

        if (isOperator(token)) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
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
    cout << "Enter Prefix expression (e.g., '* + 5 3 - 8 2'): ";
    getline(cin, expression);

    int result = evaluatePrefix(expression);
    cout << "Result: " << result << endl;

    return 0;
}


//  Example Input:

// * + 5 3 - 8 2

//  Output:

// Result: 48