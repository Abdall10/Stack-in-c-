#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node() {
        next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T>* top;

public:
    Stack() {
        top = NULL;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Function to push an item onto the stack
    void push(T item) {
        Node<T>* newNode = new Node<T>();
        newNode->data = item;
        if (isEmpty()) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode; // Top points to the new node
        }
    }

    // Function to pop the top element
    T pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow: Cannot pop from an empty stack.");
        }
        T value = top->data;
        Node<T>* delTop = top;
        top = top->next;
        delete delTop;
        return value;
    }

    // Function to get the top element without removing it
    T peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty: No top element.");
        }
        return top->data;
    }

    // Function to display the stack
    void display() {
        if (isEmpty()) {
            cout << "The stack is empty!" << endl;
            return;
        }
        Node<T>* temp = top;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to count the elements in the stack
    int count() {
        int counter = 0;
        Node<T>* temp = top;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    // Function to search for an element in the stack
    bool isFound(T item) {
        Node<T>* temp = top;
        while (temp != NULL) {
            if (temp->data == item) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to check if the stack is full
    bool isFull() {
        Node<T>* testNode = new Node<T>();
        if (testNode == NULL) {
            return true;
        }
        delete testNode;
        return false;
    }
};

int main() {
    cout << "Stack push\n";
    Stack<int> op1; // Stack for integers

    int item;
    for (int i = 0; i < 5; i++) {
        cout << "Enter an item to push: ";
        cin >> item;
        op1.push(item);
        op1.display();
    }

    cout << op1.pop() << "\n was deleted from the stack\n";
    op1.display();

    cout << op1.pop() << "\n was deleted from the stack\n";
    op1.display();

    cout << "Top element is: " << op1.peek() << endl;
    cout << "Stack contains " << op1.count() << " elements." << endl;
    cout << (op1.isFound(10) ? "Element 10 is in the stack." : "Element 10 is not in the stack.") << endl;

    return 0;
}
