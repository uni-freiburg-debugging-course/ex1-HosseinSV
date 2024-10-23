#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int randomInt32() {
    return rand() % 100000 - 50000;
}

char randomOperator() {
    int rand_op = rand() % 3;
    switch (rand_op) {
        case 0: return '+';
        case 1: return '-';
        case 2: return '*';
        default: return '+';
    }
}

string generateRandomExpression() {
    char op = randomOperator();
    int operand1 = randomInt32();
    int operand2 = randomInt32();

    return "(simplify (" + string(1, op) + " " + to_string(operand1) + " " + to_string(operand2) + "))";
}

int main() {
    srand(time(0));

    for (int i = 0; i < 10; ++i) {
        string random_input = generateRandomExpression();
        cout << random_input << endl;
    }

    return 0;
}
