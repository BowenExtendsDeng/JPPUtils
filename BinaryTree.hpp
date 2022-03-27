#pragma once

template<class T>
struct TreeNode {
    T data;
    TreeNode<T> &leftChild;
    TreeNode<T> &rightChild;
};

template<class T>
class BinaryTree {
private:
    TreeNode<T> top;
    int size = 0;
    int height = 0;
public:
    BinaryTree() = default;
    ~BinaryTree()= default;
};
