#include <iostream>
using namespace std;

// Node structure for the stack
struct node {
    int data;
    node* next;
};

node* top = NULL;

// Function declarations
void display();
void push(int value);
int pop();
int peek();
int findBottom();
void chooseStackSize();
void enterNumbersWithSize(int size);
void displayTopAndBottom();

int main() {
    chooseStackSize(); // Let the user choose the stack size

    cout << "Stack elements are:" << endl;
    display();

    displayTopAndBottom(); // Display top and bottom elements

    return 0;
}

// Function to display the stack elements
void display() {
    node* current_node;
    if (top == NULL) {
        cout << "Stack is empty." << endl;
    } else {
        current_node = top;
        while (current_node != NULL) {
            cout << current_node->data << "\n";
            current_node = current_node->next;
        }
    }
}

// Function to push an element onto the stack
void push(int value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Function to pop the top element from the stack
int pop() {
    int value;
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
        return -1;
    } else {
        node* first_node = top;
        top = first_node->next;
        value = first_node->data;
        delete first_node;
        return value;
    }
}

// Function to peek at the top element of the stack
int peek() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return -1;
    } else {
        return top->data;
    }
}

// Function to find the bottom element of the stack
int findBottom() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return -1;
    }

    node* current_node = top;
    while (current_node->next != NULL) { // Traverse until the last node
        current_node = current_node->next;
    }

    return current_node->data; // Return the data of the last node
}

// Function to allow the user to choose the stack size
void chooseStackSize() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size. Stack size must be greater than 0." << endl;
    } else {
        enterNumbersWithSize(size); // Allow the user to push numbers
    }
}

// Function to allow the user to enter numbers up to the chosen stack size
void enterNumbersWithSize(int size) {
    int value;
    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> value;
        push(value);
    }
}

// Function to display the top and bottom elements of the stack
void displayTopAndBottom() {
    if (top == NULL) {
        cout << "Stack is empty. No top or bottom element." << endl;
    } else {
        cout << "Top Element: " << peek() << endl;
        cout << "Bottom Element: " << findBottom() << endl;
    }
}
