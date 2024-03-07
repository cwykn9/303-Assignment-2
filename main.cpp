#include <iostream>
#include "Single Linked List.h"
#include "Stack.h"
using namespace std;

int main() {
    Single_Linked_List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;
    cout << "Size: " << list.find(2) << endl;

    list.insert(2, 5);
    list.remove(1);

    cout << "Front after insert and remove: " << list.front() << endl;
    cout << "Size after insert and remove: " << list.find(5) << endl;

    Stack stack;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    cout << "Top of stack: " << stack.top() << endl;

    stack.pop();

    cout << "Top of stack after pop: " << stack.top() << endl;

    cout << "Average value of stack elements: " << stack.average() << endl;

    return 0;
}
