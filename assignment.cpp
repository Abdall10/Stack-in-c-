#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Struct to store element and its next greater element
struct ElementWithNGE {
    int value;
    int nextGreater;
};

void findNextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<ElementWithNGE> result(n); // To store results
    stack<int> s; // Stack to track elements for NGE computation

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Remove elements from the stack smaller than or equal to the current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // Determine the next greater element
        int nextGreater = (s.empty() ? -1 : s.top());

        // Store the result
        result[i] = {arr[i], nextGreater};

        // Push the current element onto the stack
        s.push(arr[i]);
    }

    // Print the results
    for (const auto& element : result) {
        cout << element.value << " -> " << element.nextGreater << endl;
    }
}

int main() {
    vector<int> arr = {13, 7, 6, 12};
    cout << "Next Greater Element (NGE) for each element:\n";
    findNextGreaterElements(arr);
    return 0;
}
