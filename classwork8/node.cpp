//
//  A.cpp
//  
//
//  Created by Elina Mukhamedova on 24.03.2022.
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

int main() {
    std::cout << "List length: ";
    int n = 0;
    std::cin >> n;
    Node *list = new Node;
    list->field = -1;
    int x = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        add_node(&list, x);
    }
    print_list(&list);
    
    std::cout << "Find by value: ";
    int d = 0;
    std::cin >> d;
    std::cout << find_by_value(&list, d) << std::endl;
    
    std::cout << "Delete by value: ";
    d = 0;
    std::cin >> d;
    delete_by_value(&list, d);
    print_list(&list);
    
    std::cout << "Add value to index: ";
    int q = 0, ind = -1;
    std::cin >> q >> ind;
    add(&list, q, ind);
    print_list(&list);
    
    std::cout << "Delete all nodes" << std::endl;
    delete_list(&list);
    print_list(&list);
    delete list;
}
