//
//  stack.cpp
//  
//
//  Created by Elina Mukhamedova on 07.04.2022.
//

#include <iostream>
struct Node {
    int field;
    Node* next;
};

void add_node(Node** head_ptr, int value) {
    Node* current = *head_ptr;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new Node;
    current->next->next = nullptr;
    current->next->field = value;
}

void add(Node** head_ptr, int value, int index) {
    int i = 0;
    Node* current = *head_ptr;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (i == index) {
            break;
        }
        prev = current;
        current = current->next;
        ++i;
    }
    if (i == index) {
        Node* tmp = new Node;
        tmp->field = value;
        prev->next = tmp;
        tmp->next = current;
    }
}

void print_list(Node** head_ptr) {
    Node* current = *head_ptr;
    while (current != nullptr) {
        std::cout << current->field << "\t";
        current = current->next;
    }
    std::cout << std::endl;
}

void delete_by_value(Node** head_ptr, int value) {
    Node* current = *head_ptr;
    Node* prev = nullptr;
    bool flag = false;
    while (current != nullptr) {
        if (current->field == value) {
            flag = true;
            break;
        }
        prev = current;
        current = current->next;
    }
    if (flag == true) {
        prev->next = current->next;
        delete current;
    }
}

void delete_list(Node** head_ptr) {
    Node* current = *head_ptr;
    Node* prev = nullptr;
    while (current != nullptr) {
        prev = current;
        current = current->next;
        delete current;
    }
    (*head_ptr)->next = current;
}

int find_by_value(Node** head_ptr, int value) {
    Node* current = *head_ptr;
    int i = 0;
    bool flag = false;
    while (current != nullptr) {
        if (current->field == value) {
            flag = true;
            break;
        }
        i++;
        current = current -> next;
    }
    if (flag == true)
        return i;
    else
        return -1;
}


struct Stack {
    Node* top;
    
    Stack (int field) {
        top = new Node;
        top->field = field;
        top->next = nullptr;
    }
    
    void push(int x) {
        top->next = new Node;
        top->next->next = nullptr;
        top->next->field = x;
    }
    
    void pop(){
        if (top != nullptr)
            top = nullptr;
    }
    
    bool is_empty(){
        if (top == nullptr)
            return true;
        else
            return false;
    }
    
    Node* Top() {
        return top;
    }
};
