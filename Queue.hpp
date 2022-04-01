/**
 * @brief           a java like queue impl by cpp
 * @author          BowenDeng
 * @date            2021/3/27
 * @version 1.0 <p> define all methods that queue has in common </p>
 */

#pragma once

#include <stdexcept>

/**
 * a storage unit
 * @tparam T    type of data wanted to store
 * @version     1.0
 */
template<class T>
struct Node {
    /**
     * real place to put data
     * @version     1.0
     */
    T data;
    /**
     * pointer to point previous storage unit
     * @version     1.0
     */
    Node<T> *pre;
    /**
     * pointer to point next storage unit
     * @version     1.0
     */
    Node<T> *next;
};

template <typename T>
class Queue{
private:
    /**
     * first storage unit in Queue
     * @version     1.0
     */
    Node<T> *head;
    /**
     * last storage unit in Queue
     * @version     1.0
     */
    Node<T> *tail;
    /**
     * amount of storage units
     * @version     1.0
     */
    int size = 0;

public:
    /**
     * default constructor to create an instance of doubly linked list
     * @version     1.0
     */
    Queue<T>() = default;

    /**
     * free all storage units in a instance of LinkedList
     * @version     1.3
     */
    ~Queue<T>() {
        for (int i = 0; i < size; ++i) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
     * enqueue a new element at the tail of Queue
     * @param data      a new element to add into LinkedList
     * @version         1.0
     */
    void enqueue(T data) {
        if (size == 0) {
            head = new Node<T>();
            tail = head;
            head->data = data;
            size++;
        } else {
            auto *temp = new Node<T>();
            temp->data = data;
            temp->pre = tail;
            tail->next = temp;
            tail = temp;
            size++;
        }
    }

    /**
     * remove a data
     * @param index     index which contains the data wanted to erase
     * @version         1.0
     */
    T dequeue() {
        Node<T> *temp = head;
        T data = head->data;
        head = head->next;
        tail->next = head;
        head->pre = tail;
        delete temp;
        size--;
        return data;
    }

    /**
     * find first index of a data in Queue,if it
     * is not found,return -1 instead.
     * @param data      a data that wanted its index
     * @return          first index of the data in LinkedList
     * @version         1.0
     */
    int indexOf(T data) {
        Node<T> *temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->data == data) {
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    /**
     * return a value in Queue by offering its index
     * @param index     value want to get
     * @return          value of this designated index
     * @version         1.0
     */
    T valueOf(int index) {
        if (index > size) {
            throw std::out_of_range("in\"LinkedList::valueOf\",invalid index:index beyond capacity");
        } else if (size == index) {
            return tail->data;
        } else if (index < 0) {
            throw std::underflow_error("in\"LinkedList::valueOf\",index should equals or beyond zero");
        } else {
            Node<T> *temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    /**
     * find last index of a data in Queue,if it
     * is not found,return -1 instead.
     * @param data      a data that wanted its index
     * @return          first index of the data in array "elementData"
     * @version         1.0
     */
    int lastIndexOf(T data) {
        Node<T> *temp = head;
        for (int i = size - 1; i >= 0; i++) {
            if (temp->data == data) {
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    /**
    * get the amount of real data that stored in Queue
    * @return       size of an ArrayList
    * @version      1.0
    */
    int length() {
        return size;
    }

    /**
     * transfer Queue into standard array in cpp
     * @return      data in array form
     * @version     1.0
     */
    T *toArray() {
        auto *temp = new T[size];
        Node<T>* node = head;
        for (int i = 0; i < size; ++i) {
            temp[i] = node->data;
            node = node->next;
        }
        return temp;
    }
};