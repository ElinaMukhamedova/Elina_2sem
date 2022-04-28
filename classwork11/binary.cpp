//
//  binary.cpp
//  
//
//  Created by Elina Mukhamedova on 28.04.2022.
//

#include <iostream>

struct Node {
  Node* parent;
  Node* left;
  Node* right;
  int value;
}

void pre_order(Node* n) {
  std::cout << n->value << '\n';
  pre_order(n->left);
  pre_order(n->right);
}

void in_order(Node* n) {
    in_order(n->left);
    std::cout << n->value << '\n';
    in_order(n->right);
}

void post_order(Node* n) {
    post_order(n->left);
    post_order(n->right);
    std::cout << n->value << '\n';
}

Node* find(Node* n, int x) {
    if (n->value == x)
        return true;
    find(n->left, x);
    find(n->right, x);
}  // Поиск элемента и выдача указателя на него (иначе nullptr)

void add(Node* root, int value) {
    if (root == nullptr)
        root = new Node;
    else
        if 
}  // Подаем корень дерева и добавляем новый элемент
void remove(Node* root, int value);  // Удаляем элемент из дерева, если такой есть
Node* min(Node* root);  // Поиск минимального элемента
Node* max(Node* root);  // Поиск максимального элемента
