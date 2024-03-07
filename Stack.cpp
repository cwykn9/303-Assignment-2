#include "Stack.h"
using namespace std;

bool Stack::isEmpty() const {
    return elements.empty();
}

void Stack::push(int value) {
    elements.push_back(value);
}

void Stack::pop() {
    if (!isEmpty())
        elements.pop_back();
}

int Stack::top() const {
    if (!isEmpty())
        return elements.back();
    else
        throw out_of_range("Stack is empty");
}

double Stack::average() const {
    if (!isEmpty()) {
        double sum = 0;
        for (int value : elements)
            sum += value;
        return sum / elements.size();
    } else {
        throw logic_error("Cannot compute average of an empty stack");
    }
}
