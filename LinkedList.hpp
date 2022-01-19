#pragma once

#include <stdexcept>

/**
 * @brief  a java like link list impl by cpp
 *
 * @tparam T type of data that to store
 * @author BowenDeng
 * @date 2021/1/19
 * @version 1.0
 */
template<class T>
struct Node{
    T data;
    Node<T>* pre;
    Node<T>* next;
};

template<class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size = 0;
public:
    LinkedList<T>() = default;

    ~LinkedList<T>(){
        Node<T>* data = head;
        while(data != nullptr){
            Node<T>* nextNode = head->next;
            delete data;
            data = nextNode;
        }
    }

    void add(T data){
        if(size == 0){
            head = new Node<T>();
            tail = head;
            head->data = data;
            size++;
        }else{
            auto* temp = new Node<T>();
            temp->data = data;
            temp->pre = tail;
            tail->next = temp;
            tail = temp;
            size++;
        }
    }

    void insert(int index,T data){
        if(index > size){
            throw std::out_of_range("invalid index:index beyond capacity");
        }else if(size == index){
            add(data);
        }else if(index < 0){
            throw std::underflow_error("index should equals or beyond zero");
        }else{
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            auto* newNode = new Node<T>();
            newNode->next = temp->next;
            newNode->pre = temp;
            temp->next->pre = newNode;
            temp->next = newNode;
            size++;
        }
    }

    void update(int index,T data){
        if(index > size){
            throw std::out_of_range("invalid index:index beyond capacity");
        }else if(size == index){
            tail->data = data;
        }else if(index < 0){
            throw std::underflow_error("index should equals or beyond zero");
        }else{
            Node<T>* temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            temp->data = data;
        }
    }

    void remove(int index){
        if(index > size){
            throw std::out_of_range("invalid index:index beyond capacity");
        }else if(size == index){
            Node<T>* temp = tail;
            tail = tail->pre;
            delete temp;
        }else if(index < 0){
            throw std::underflow_error("index should equals or beyond zero");
        }else if(index == 0) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
        }else{
            Node<T>* temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            delete temp;
            size--;
        }
    }


    int indexOf(T data){
        Node<T>* temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->data == data) {
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    T valueOf(int index){
        if(index > size){
            throw std::out_of_range("invalid index:index beyond capacity");
        }else if(size == index){
            Node<T>* temp = tail;
            tail = tail->pre;
            delete temp;
        }else if(index < 0){
            throw std::underflow_error("index should equals or beyond zero");
        }else{
            Node<T>* temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    int lastIndexOf(T data){
        Node<T>* temp = head;
        for (int i = size - 1; i >= 0; i++) {
            if (temp->data == data) {
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    int length(){
        return size;
    }
};
