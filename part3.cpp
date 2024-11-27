#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to display the stack elements
void display(stack<pair<int, string>> Stack) {
    while (!Stack.empty()) {
        // Access the top element of the stack
        pair<int, string> element = Stack.top();
        cout << "Value: " << element.first << ", Number: " << element.second << endl;
        Stack.pop(); // Remove the top element
    }
}

int main() {
    // Define a stack of pairs: each pair contains an integer and a string
    stack<pair<int, string>> numbersStack;

    // Push pairs (number, string) onto the stack
    numbersStack.push({10, "Data 1"});
    numbersStack.push({20, "Data 2"});
    numbersStack.push({30, "Data 3"});
    numbersStack.push({40, "Data 4"});
    numbersStack.push({50, "Data 5"});
    
    display(numbersStack);

    return 0;
}
