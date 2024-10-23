#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int evaluate(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        default:
            throw invalid_argument("Unsupported operator");
    }
}

void simplifyExpression(const string& input) {
    if (input.find("(simplify") != 0 || input.back() != ')') {
        throw invalid_argument("Invalid input format");
    }
    size_t start = input.find('(') + 1;
    size_t end = input.find_last_of(')');
    string expression = input.substr(start, end - start);
    expression = expression.substr(9);
    size_t op_start = expression.find('(') + 1;
    size_t op_end = expression.find_last_of(')');

    if (op_start == string::npos || op_end == string::npos) {
        throw invalid_argument("Invalid operator expression");
    }
    string op_expr = expression.substr(op_start, op_end - op_start);
    char op;
    int operand1, operand2;
    stringstream ss(op_expr);
    string operator_symbol;
    ss >> operator_symbol >> operand1 >> operand2;
    if (operator_symbol == "+") {
        op = '+';
    } else if (operator_symbol == "-") {
        op = '-';
    } else if (operator_symbol == "*") {
        op = '*';
    } else {
        throw invalid_argument("Invalid operator");
    }

    int result = evaluate(op, operand1, operand2);
    if (op == '-') {
        cout << "(- " << -result << ")" << endl;
    } else {
        cout << result << endl;
    }
}

int main() {
    string input;

    while (getline(cin, input)) {
        try {
            simplifyExpression(input);
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
