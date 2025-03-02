/*#include "StackArray.h"

using namespace std;

template <class T>
void StackArray<T>::push(const T& element) {
    if (isFull()) {
        throw StackOverflow();
    }
    stack[++top] = element;
}

template <class T>
T StackArray<T>::pop() {
    if (isEmpty()) {
        throw StackUnderflow();
    }
    return stack[top--];
}

template <class T>
bool StackArray<T>::isFull() {
    return top == size - 1;
}

template <class T>
bool StackArray<T>::isEmpty() {
    return top == -1;
}   


bool checkBalanceBrackets(const char* text, const int maxDeep) {
    StackArray<char> stack(maxDeep);

    for (int i = 0; text[i] != '\0'; ++i) {
        char currentChar = text[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            try {
                stack.push(currentChar);
            } catch (const StackOverflow& e) {
                std::cerr << e.what() << std::endl;
                return false;
            }
        } 
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            if (stack.isEmpty()) {
                return false;
            }

            char topChar;
            try {
                topChar = stack.pop();
            } catch (const StackUnderflow& e) {
                std::cerr << e.what() << std::endl;
                return false;
            }

            if ((currentChar == ')' && topChar != '(') ||
                (currentChar == ']' && topChar != '[') ||
                (currentChar == '}' && topChar != '{')) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

template class StackArray<char>;
template class StackArray<int>;*/