#include "StackArray.h"
#include <iostream>
#include <string>

using namespace std;

void testBasicStackOperations();
void testStackOverflow();
void testStackUnderflow();
void testBracketBalancing();

int main() {
    
    testBasicStackOperations();
    testStackOverflow();
    testStackUnderflow();
    testBracketBalancing();
    
    return 0;
}

void testBasicStackOperations() {

    StackArray<int> stack(5);
    if (!stack.isEmpty()) {
        cout << "Error: New stack should be empty" << endl;
    }
    stack.push(10);
    stack.push(20);
    stack.push(30);
    if (stack.isEmpty()) {
        cout << "Error: Stack should not be empty after push" << endl;
    }
    if (stack.pop() != 30 || stack.pop() != 20 || stack.pop() != 10) {
        cout << "Error: Incorrect order of element extraction" << endl;
    }
    if (!stack.isEmpty()) {
        cout << "Error: Stack should be empty after extracting all elements" << endl;
    }
}
void testStackOverflow() {
    try {
        StackArray<int> stack(3);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        cout << "Attempting to push extra element" << endl;
        stack.push(4);
    } catch (const StackOverflow& e) {
        cerr << e.what() << endl;
    }
}

void testStackUnderflow() {
    try {
        StackArray<int> stack(3);
        stack.push(1);
        stack.pop();
        cout << "Attempting to pop from an empty stack" << endl;
        stack.pop();
    } catch (const StackUnderflow& e) {
        cerr << e.what() << endl;
    }
}

void testBracketBalancing() {
    string testCases[] = {"", "[", "{[{}]}", "([)]", "((())))", "{[()]}", "{[({[()]})}"}; 
    for (int i = 0; i < 7; ++i) {
        bool result = checkBalanceBrackets(testCases[i].c_str(), 5);
        cout << "Tested: " << testCases[i] << " Result: " << (result ? "True" : "False") << endl;
    }
}
