#ifndef STACKARRAY_H
#define STACKARRAY_H

#include "Stack.h"
#include <exception>
#include <iostream>

class StackOverflow : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Stack Overflow";
    }
};

class StackUnderflow : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Stack Underflow";
    }
};

class WrongStackSize : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Wrong Stack Size";
    }
};

template <class T>
class StackArray : public Stack<T>
{
private:
    size_t size;
    int top;
    T* stack;

public:
    StackArray(size_t size) : size(size), top(-1) {
        if (size <= 0) {
            throw WrongStackSize();
        }
        stack = new T[size];
    }

    ~StackArray() {
        delete[] stack;
    }
    
    void push(const T& e) override {
        if (isFull()) {
            throw StackOverflow();
        }
        stack[++top] = e;
    }
    
    T pop() override {
        if (isEmpty()) {
            throw StackUnderflow();
        }
        return stack[top--];
    }
    
    bool isEmpty() override {
        return top == -1;
    }
    
    bool isFull() override {
        return top == size - 1;
    }
};

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

#endif