// reverse infix
// convert infix to postfix
// reverse postfix

#include <iostream>
#include <stack>
#include <unordered_map>
#include <algorithm> // for reverse

using namespace std;

// Function to check if a character is an operand
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to convert infix to prefix notation
string infixToPrefix(string infix) {
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());
    
    stack<char> operators;
    string prefix;
    
    // Operator precedence map
    unordered_map<char, int> precedence = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2},
        {'^', 3}
    };
    
    for (char c : infix) {
        if (isOperand(c)) {
            prefix += c;
        }
        else if (c == ')') {
            operators.push(c);
        }
        else if (c == '(') {
            // Pop until ')' is found
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove the ')'
        }
        else { // Operator
            while (!operators.empty() && operators.top() != ')' && 
                   precedence[c] < precedence[operators.top()]) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    // Pop all remaining operators
    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }
    
    // Step 3: Reverse the final string
    reverse(prefix.begin(), prefix.end());
    
    return prefix;
}

int main() {
    string infix = "a+b*(c^d-e)";
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    
    // More test cases
    cout << "\nAdditional Test Cases:\n";
    cout << "Infix: (A+B)*C-D  Prefix: " << infixToPrefix("(A+B)*C-D") << endl;
    cout << "Infix: A+B*C-D/E  Prefix: " << infixToPrefix("A+B*C-D/E") << endl;
    cout << "Infix: K+L-M*N+(O^P)*W/U/V*T+Q  Prefix: " 
         << infixToPrefix("K+L-M*N+(O^P)*W/U/V*T+Q") << endl;
    
    return 0;
}