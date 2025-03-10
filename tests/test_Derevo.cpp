//Copyright 2024 Ramzan Kamaletdinov

#include <gtest.h>
#include "../lib_Derevo/Derevo.h"

int main() {
    TNode<int>* root = new TNode<int>(10);
    root->left = new TNode<int>(20);
    root->right = new TNode<int>(50);
    root->left->left = new TNode<int>(30);
    root->left->right = new TNode<int>(40);
    root->right->right = new TNode<int>(60);
    root->right->right->left = new TNode<int>(70);
    root->right->right->right = new TNode<int>(-80);
    root->right->right->left->left = new TNode<int>(-90);
    root->right->right->left->right = new TNode<int>(99);

    std::cout << "Дерево:\n";
    printTree(root);
    std::cout << std::endl;

    return 0;
}