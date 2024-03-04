
#include <iostream>
#include "Tree.h"

template <class T>
int calculateSum(const TreeNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    int sum = 0;
    sum += node->getValue();
    sum += calculateSum(node->getLeft());
    sum += calculateSum(node->getRight());
    return sum;
}

template <class T>
bool findValue(const TreeNode<T>* node, const T& value) {
    if (node == nullptr) {
        return false;
    }
    if (node->getValue() == value) {
        return true;
    }
    else {
        if (findValue(node->getLeft(), value) == true) {
            return true;
        }
        else if (findValue(node->getRight(), value) == true) {
            return true;
        }
        else
            return false;
        
    }
}

int main()
{
    Tree<int> tree;
    tree.setRoot(new TreeNode<int>{ 3 });
    tree.getRoot()->setRight(new TreeNode<int>{ 5 });
    tree.getRoot()->setLeft(new TreeNode<int>{ 8 });

    tree.printPreorder();
    std::cout << "\n" << std::endl;
    tree.printInorder();
    std::cout << "\n" << std::endl;
    tree.printPostorder();
    std::cout << "\n" << std::endl;
    int sum = calculateSum(tree.getRoot());
    std::cout << sum << std::endl;

    std::cout << findValue(tree.getRoot(), 5) << std::endl;
    std::cout << findValue(tree.getRoot(), 10) << std::endl;
}


