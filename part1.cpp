#include <iostream>
using namespace std;

// Stacks 
// stack - Last In First Out (LIFO)
// To build a stack an array or linked list.
//push(): Insert the element at the top of the stack.
//pop(): Return the top element.
//Peek(): Return the element from the top of the stack without removing it.
//Display(): Display all the elements of the stack.
//isEmpty(): Check if the stack is empty or not.
//isFull(): Check if the stack is full or not. ( Logically, a stack cannot be full in heap, but a heap can sometimes be full )
//Count(): Return the count of stack items.
//Search(): Search for a specific item in the stack.

class Node{
    public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
};

class Stack{
    Node* top;
 public:
 Stack()
 {
    top = NULL;
 }

 // function to check if the stack is empty
 bool isEmpty()
 {
    if( top == NULL)
    {
        return true;
    }else{
        return false;
    }
 }

 // function to push
   void push(int item)
   {
   Node* newNode = new Node();
   newNode->data = item;
    if(isEmpty()){
        top=newNode;
    }else{
        newNode->next = top;
        top = newNode; // top points to the new node
    }
   }

// function to pop 
int pop()
{
  int value;  
  Node* deltop= top;
  value = top->data;
  top=top->next;
  delete deltop;
  return value;
}

// function to get the top element
int Peek()
{
    return top->data;
}

// function to Display
   void display()
   {
     Node* temp = top;
     while(temp != NULL){
        cout << temp->data << "\t";
        temp = temp->next;
     }
     cout<<endl;
   }

// function to get the size of the stack
   int count()
   {
    int counter =0;
     Node* temp = top;
     while(temp != NULL){
        counter++;
        temp = temp->next;
     }
     return counter;
   }

// function to Search element
   bool IsFound(int item)
   {
    bool found = false;
      Node* temp = top;
     while(temp != NULL)
     {
        if(temp->data==item)
            found = true;
            temp=temp->next;        
     }
      return found;
   }

// function to check if the stack is Full  
   bool isFull()
   {
    Node* nen = new Node;
    if(nen == NULL){
        cout<<"The Stack is Full, cannot add more elements"<<endl;
    }
   }

};

int main() {
    cout << "Stack push \n";
    Stack op1;

    int item;
    for(int i=0; i<4; i++)
    {
        cout<<"Enter Item to push elements: \n";
        cin>>item;
        op1.push(item);
        op1.display();
    }

    cout << op1.pop() <<"\n was deleted from stack \n";
    op1.display();

    cout << op1.pop() <<"\n was deleted from stack \n";
    op1.display();
    
    return 0;
}