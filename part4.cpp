#include <iostream>
using namespace std;
// stack using array have a 5 values

#define MAX 5
int stack[MAX];
int top = -1;

void push(int items);
int pop();
int peek();
void display();

int main() {
   cout<<"Stack using array \n"; 
   cout<<"Stack Push \n";
   push(10);
   push(20);
   push(30);
   push(40);
   push(50);
   display();
   cout<<"Stack Pop \n";
   pop();
   display();
   cout<<"Stack Peek \n";
   peek();
   display();   

    return 0;
}

// Function to add an element to the stack
void push(int items) {
    if (top == MAX - 1) {
        cout << "Stack Overflow" << endl;
    }else{
    top++;
    stack[top] = items;
    }

}

// function pop () is used to remove the top element of the stack
int pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return -1;
    }else{
        return stack[top--];
    }
}

// function peek () is used to get the top element of the stack without removing it
int peek() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return -1;
    }else{
        return stack[top];
    }
}

// function display () is used to display the elements of the stack
void display() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
    }else{
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}


/*
    |              |
    |______________|
    |     50       |  4   <- top
    |______________|
    |     40       |  3
    |______________|
    |     30       |  2
    |______________|
    |     20       |  1
    |______________|
    |     10       |  0  
    |______________|     
       
         Stack
    
 */