#include "Single Linked List.h"
using namespace std;

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty())
        pop_front();
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (num_items == 0) {
            tail = nullptr;
        }
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (!empty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        num_items--;
    }
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (!empty()) {
        return head->data;
    } else {
        throw out_of_range("List is empty");
    }
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (!empty()) {
        return tail->data;
    } else {
        throw out_of_range("List is empty");
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index <= num_items) {
        if (index == 0) {
            push_front(item);
        } else if (index == num_items) {
            push_back(item);
        } else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* new_node = new Node(item, current->next);
            current->next = new_node;
            num_items++;
        }
    } else {
        push_back(item); 
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index < num_items) {
        if (index == 0) {
            pop_front();
        } else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            num_items--;
        }
        return true;
    }
    return false;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr && current->data != item) {
        current = current->next;
        index++;
    }
    return (current != nullptr) ? index : num_items;
}
