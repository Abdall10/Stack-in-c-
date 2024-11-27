#include <iostream>
#include <string>
using namespace std;
// Stack using linked list
// Student name and score
// Node structure for the stack
struct node {
    string studentName;
    int score;
    node* next;
};

node* top = NULL;

// Function declarations
void push(string name, int score);
void display();
void enterStudentScores();
void findHighestScores();
void findLowestScores();
void countSuccessAndFailure();
void calculateSuccessPercentage();

int main() {
    cout << "Enter the students' grades, making sure the grades are out of 50:" << endl;
    enterStudentScores();

    cout << "\nStack of student scores:" << endl;
    display();

    findHighestScores();
    findLowestScores();
    countSuccessAndFailure();
    calculateSuccessPercentage();

    return 0;
}

// Function to push a student's name and score onto the stack
void push(string name, int score) {
    node* newNode = new node;
    newNode->studentName = name;
    newNode->score = score;
    newNode->next = top;
    top = newNode;
}

// Function to display all students and their scores
void display() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }

    node* current_node = top;
    while (current_node != NULL) {
        cout << current_node->studentName << " - Score: " << current_node->score << endl;
        current_node = current_node->next;
    }
}

// Function to let the user input scores for 10 students
void enterStudentScores() {
    for (int i = 1; i <= 10; i++) {
        string studentName = "Student " + to_string(i);
        int score;

        do {
            cout << "Enter the score for " << studentName << " : ";
            cin >> score;

            if (score < 0 || score > 50) {
                cout << "Enter the students' grades with an integer number and ensure that the grades are out of 50:" << endl;
            }
        } while (score < 0 || score > 50); // Validate that the score is between 0 and 50

        push(studentName, score);
    }
}

// Function to find and display students with the highest score
void findHighestScores() {
    if (top == NULL) {
        cout << "Stack is empty. No scores available." << endl;
        return;
    }

    node* current_node = top;
    int highestScore = current_node->score;

    // Find the highest score
    while (current_node != NULL) {
        if (current_node->score > highestScore) {
            highestScore = current_node->score;
        }
        current_node = current_node->next;
    }

    // Display all students with the highest score
    cout << "\nHighest Score: " << highestScore << " by the following students:" << endl;
    current_node = top;
    while (current_node != NULL) {
        if (current_node->score == highestScore) {
            cout << current_node->studentName << endl;
        }
        current_node = current_node->next;
    }
}

// Function to find and display students with the lowest score
void findLowestScores() {
    if (top == NULL) {
        cout << "Stack is empty. No scores available." << endl;
        return;
    }

    node* current_node = top;
    int lowestScore = current_node->score;

    // Find the lowest score
    while (current_node != NULL) {
        if (current_node->score < lowestScore) {
            lowestScore = current_node->score;
        }
        current_node = current_node->next;
    }

    // Display all students with the lowest score
    cout << "\nLowest Score: " << lowestScore << " by the following students:" << endl;
    current_node = top;
    while (current_node != NULL) {
        if (current_node->score == lowestScore) {
            cout << current_node->studentName << endl;
        }
        current_node = current_node->next;
    }
}

// Function to count and display the number of successful and failed students
void countSuccessAndFailure() {
    if (top == NULL) {
        cout << "Stack is empty. No scores available." << endl;
        return;
    }

    int successful = 0, failed = 0;
    node* current_node = top;

    while (current_node != NULL) {
        if (current_node->score >= 25) {
            successful++;
        } else {
            failed++;
        }
        current_node = current_node->next;
    }

    cout << "\nNumber of successful students: " << successful << endl;
    cout << "Number of failed students: " << failed << endl;
}

// Function to calculate and display the success percentage
void calculateSuccessPercentage() {
    if (top == NULL) {
        cout << "Stack is empty. No scores available." << endl;
        return;
    }

    int totalStudents = 0, successful = 0;
    node* current_node = top;

    while (current_node != NULL) {
        totalStudents++;
        if (current_node->score >= 25) {
            successful++;
        }
        current_node = current_node->next;
    }

    double successPercentage = (successful / (double)totalStudents) * 100.0;

    cout << "\nSuccess Percentage: " << successPercentage << "%" << endl;
}
