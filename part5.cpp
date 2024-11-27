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

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    cout << "Stack elements are:" << endl;
    display();

    cout << "Bottom Element: " << findBottom() << endl; 
    pop();
    cout << "Top Element: " << peek() << endl;

    return 0;
}

// Function to display the stack elements
void display() {
    node* current_node;
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
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
        cout << "Stack Underflow" << endl;
        return -1;
    } else {
        return top->data;
    }
}

// Function to find the bottom element of the stack
int findBottom() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    node* current_node = top;
    while (current_node->next != NULL) { // Traverse until the last node
        current_node = current_node->next;
    }

    return current_node->data; // Return the data of the last node
}
