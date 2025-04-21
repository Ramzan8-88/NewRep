// Copyright 2024 Ramzan Kamaletdinov

#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_

#include <iostream>
#include <stdexcept>
#include <string>
#include <stack>

template <typename T>
class TStack {
 private:
    T* _data;
    size_t _size;
    size_t _top;

 public:
    explicit TStack(size_t size) : _size(size), _top(0) {
        _data = new T[_size];
    }

    ~TStack() {
        delete[] _data;
    }

    void push(const T& value) {
        if (_top >= _size) {
            throw std::overflow_error("Stack overflow");
        }
        _data[_top++] = value;
    }

    T pop() {
        if (_top == 0) {
            throw std::underflow_error("Stack underflow");
        }
        return _data[--_top];
    }

    T top() const {
        if (_top == 0) {
            throw std::underflow_error("Stack is empty");
        }
        return _data[_top - 1];
    }

    bool isEmpty() const {
        return _top == 0;
    }

    size_t size() const {
        return _top;
    }
};

bool isValidExpression(const std::string& expression) {
    std::stack<char> s;
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{' || ch == '|') {
            if (ch == '|' && !s.empty() && s.top() == '|') {
                s.pop();
            } else {
                s.push(ch);
            }
        } else if (ch == ')' || ch == ']' || ch == '}' || ch == '|') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{') ||
                (ch == '|' && top == '|')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

#endif  // LIB_STACK_STACK_H_
