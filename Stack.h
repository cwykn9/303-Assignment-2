#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    bool isEmpty() const;
    void push(int value);
    void pop();
    int top() const;
    double average() const;
};

#endif
