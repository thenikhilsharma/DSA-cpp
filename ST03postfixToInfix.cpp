#include <iostream>
#include <stack>
#include <string>
#include <cctype> // for isalnum()

using namespace std;

// Function to check if character is an operand (letter or digit)
bool isOperand(char c) {
    return isalnum(c);
}

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> s;
    
    for (char c : postfix) {
        if (isOperand(c)) {
            // Push operands as single-character strings
            s.push(string(1, c));
        }
        else {
            // Operator encountered - pop two operands
            if (s.size() < 2) {
                return "Invalid postfix expression";
            }
            
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            
            // Combine with operator and push back
            string expr = "(" + op1 + c + op2 + ")";
            s.push(expr);
        }
    }
    
    // Final check
    if (s.size() != 1) {
        return "Invalid postfix expression";
    }
    
    return s.top();
}

int main() {
    string postfix = "ab+c*";
    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << postfixToInfix(postfix) << endl;
    
    // More test cases
    cout << "\nAdditional Test Cases:\n";
    cout << "Postfix: ab+cd-*  Infix: " << postfixToInfix("ab+cd-*") << endl;
    cout << "Postfix: abc*+de/-  Infix: " << postfixToInfix("abc*+de/-") << endl;
    cout << "Postfix: abcd^e-fgh*+^*+i-  Infix: "
         << postfixToInfix("abcd^e-fgh*+^*+i-") << endl;
    
    // Invalid cases
    cout << "\nInvalid Case Testing:\n";
    cout << "Postfix: ab+*  Infix: " << postfixToInfix("ab+*") << endl;
    cout << "Postfix: a+  Infix: " << postfixToInfix("a+") << endl;
    
    return 0;
}