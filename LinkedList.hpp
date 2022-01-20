/**
 * @brief  a java like link list impl by cpp
 * @author BowenDeng
 * @date 2021/1/19
 * @version 1.0 <p> impl a doubly linked list with add, insert, update, remove... methods </p>
 * @version 1.1 <p> 2021/1/19
 *              <p> add circular doubly linked list as a alternative choice </p>
 *              <p> fixed some bug </p>
 * @version 1.2 <p> 2021/1/19
 *              <p> add one parameter constructor to ArrayList.Now developers can create
 *                  an instance by passing an cpp array </p>
 * @version 1.3 <p> 2021/1/20
 *              <p> fix bug in ~LinkedList<>()</p>
 */

#pragma once

/**
 * a storage unit
 * @tparam T type of data wanted to store
 * @version 1.0
 */
template<class T>
struct Node {
    /**
     * real place to put data
     * @version 1.0
     */
    T data;
    /**
     * pointer to point previous storage unit
     * @version 1.0
     */
    Node<T> *pre;
    /**
     * pointer to point next storage unit
     * @version 1.0
     */
    Node<T> *next;
};

#include <stdexcept>
#include "List.hpp"

/**
 * @brief  a java like link list impl by cpp
 *
 * @tparam T type of data that to store
 * @version 1.0
 */
template<class T>
class LinkedList : public List<T>{
private:
    /**
     * first storage unit in LinkedList
     * @version 1.0
     */
    Node<T> *head;
    /**
     * last storage unit in LinkedList
     * @version 1.0
     */
    Node<T> *tail;
    /**
     * amount of storage units
     * @version 1.0
     */
    int size = 0;
    /**
     * <p>
     * to tell whether the linked list is a circular linked list
     * </p>
     *
     * <p>
     * LinkedList is a non-circular, doubly linked list when
     * instance is created by default constructor. It can also be
     * a circular linked list when passing"true" into one parameter
     * constructor.Its state can be modified by calling method
     * "doCircular" and "deCircular".
     * </p>
     *
     * @version 1.1
     */
    bool isCircular = false;
public:
    /**
     * default constructor to create an instance of doubly linked list
     * @version 1.0
     */
    LinkedList<T>() = default;

    /**
     * default constructor for LinkedList]
     * @version 1.0
     */
    explicit LinkedList<T>(bool isCircular) {
        if (isCircular) {
            this->isCircular = isCircular;
        }
    }

    /**
     * initialize linked list by a cpp array
     * @param array a cpp array to parse into ArrayList
     * @param length length of the passing array
     * @version 1.2
     */
    explicit LinkedList<T>(T array[],int length){
        for (int i = 0; i < length; ++i) {
            add(array[i]);
        }
    }

    /**
     * free all storage units in a instance of LinkedList
     * @version 1.3
     */
    ~LinkedList<T>() {
        for (int i = 0; i < size; ++i) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
     * add a new element at the tail of LinkedList
     * @param data
     * @version 1.0
     */
    void add(T data) {
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

        if (isCircular) {
            doCircular();
        }
    }

    /**
     * insert a data into a designated place by giving its index.
     * Origin data in this index and after this index will move
     * backward by one index.
     * @param index index of the data want to break in
     * @param data data which wanted to insert into LinkedList
     * @version 1.3
     */
    void insert(int index, T data) {
        if (index > size) {
            throw std::out_of_range("in\"LinkedList::insert\", invalid index:index beyond size");
        } else if (size == index) {
            add(data);
        } else if (index < 0) {
            throw std::underflow_error("in\"LinkedList::insert\", index should equals or beyond zero");
        } else {
            auto *temp = head;
            auto *newNode = new Node<T>();
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            newNode->data = data;
            newNode->pre = temp->pre;
            newNode->next = temp;
            temp->pre = newNode;
            if(index == 0){
                head = newNode;
            } else {
                newNode->pre->next = newNode;
            }
            size++;
        }
    }

    /**
     * update a data by a designated index
     * @param index index of update wanted data
     * @param data data wanted to update
     * @version 1.0
     */
    void update(int index, T data) {
        if (index > size) {
            throw std::out_of_range("in\"LinkedList::update\", invalid index:index beyond size");
        } else if (size == index) {
            tail->data = data;
        } else if (index < 0) {
            throw std::underflow_error("in\"LinkedList::update\", index should equals or beyond zero");
        } else {
            Node<T> *temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            temp->data = data;
        }
    }

    /**
     * remove a data by its index
     * @param index index which contains the data wanted to erase
     * @version 1.0
     */
    void remove(int index) {
        if (index > size) {
            throw std::out_of_range("in\"LinkedList::remove\", invalid index:index beyond size");
        } else if (size == index) {
            Node<T> *temp = tail;
            tail = tail->pre;
            delete temp;
        } else if (index < 0) {
            throw std::underflow_error("in\"LinkedList::remove\", index should equals or beyond zero");
        } else if (index == 0) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
        } else {
            Node<T> *temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            delete temp;
            size--;
        }
    }

    /**
     * find first index of a data in LinkedList,if it
     * is not found,return -1 instead.
     * @param data a data that wanted its index
     * @return first index of the data in LinkedList
     * @version 1.0
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
     * return a value in LinkedList by offering its index
     * @param index value want to get
     * @return value of this designated index
     * @version 1.0
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
     * find last index of a data in LinkedList,if it
     * is not found,return -1 instead.
     * @param data a data that wanted its index
     * @return first index of the data in array "elementData"
     * @version 1.0
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
    * get the amount of real data that stored in LinkedList
    * @return size of an ArrayList
    * @version 1.0
    */
    int length() {
        return size;
    }

    /**
     * modify linked list to circular linked list
     * @version 1.1
     */
    void doCircular() {
        isCircular = true;
        tail->next = head;
        head->pre = tail;
    }

    /**
     * modify doubly circular linked list to non-circular doubly linked list
     * @version 1.1
     */
    void deCircular() {
        isCircular = false;
        tail->next = nullptr;
        tail->pre = nullptr;
    }

    /**
     * transfer LinkedList into standard array in cpp
     * @return data in array form
     * @version 1.0
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
