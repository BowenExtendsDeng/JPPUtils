#pragma once

template<class T>
struct TreeNode {
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

template<class T>
class BinaryTree {
private:
    TreeNode<T> *top;
    TreeNode<T> *viewer = top;
public:
    BinaryTree() = default;
    ~BinaryTree(){
    }

    TreeNode<T> *getViewer(){
        return viewer;
    }
};
