/**
 * @brief           a java like stack impl by cpp
 * @author          BowenDeng
 * @date            2021/3/27
 * @version 1.0 <p> define all methods that stack has in common </p>
 */

#pragma once

#include <stdexcept>

template <typename T>
class Stack{
private:
    /**
     * capacity of array "element data" when it is created by
     * no-argument constructor
     * @version     1.0
     */
    const static int DEFAULT_CAPACITY = 10;
    /**
     * bound of array "element data"
     * @version     1.0
     */
    int capacity{};
    /**
     * number of valid data stored in array "element data"
     * @version     1.0
     */
    int size = 0;
    /**
     * real place to store data
     * @version     1.0
     */
    T *elementData;

    /**
     * expand capacity of array "elementData". It grows 1.5
     * times than before everytime it reaches to the bound.
     * @version     1.0
     */
    void inline expandCapacity() {
        capacity *= 1.5;
        T *newArray = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = elementData[i];
        }
        delete[] elementData;
        elementData = newArray;
    }

    /**
     * reduce capacity when size far away from the bound.It reduce
     * one third of its capacity and it will ensure no valid data
     * will be missing during this action.
     * @version     1.0
     */
    void inline reduceCapacity() {
        if ((size * 1.5) < capacity) {
            capacity = capacity / 1.5 + 1;
            T *newArray = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = elementData[i];
            }
            delete[] elementData;
            elementData = newArray;
        }
    }

public:
    /**
     * none argument constructor of class ArrayList. It will
     * allocate an empty array size of 10.
     * @version     1.0
     */
    Stack<T>() {
        capacity = DEFAULT_CAPACITY;
        this->elementData = new T[DEFAULT_CAPACITY];
    }

    /**
     * initialize dynamic array with a specific size
     * @param initialCapacity   initial capacity of array
     *                          "elementData".
     *                          It should be above zero
     * @version                 1.0
     */
    explicit Stack<T>(int initialCapacity) {
        if (initialCapacity > 0) {
            capacity = initialCapacity;
            this->elementData = new T[initialCapacity - 1];
        } else {
            throw std::underflow_error("in\"ArrayList::ArrayList<T>(int initialCapacity)\","
                                       "initial capacity should beyond zero");
        }
    }

    /**
     * free memory of array "elementData"
     * @version     1.0
     */
    ~Stack() { delete elementData; }

    /**
     * add a new element into array "elementData".Also expand
     * elementData by calling expandCapacity when it finds that
     * size is equal to capacity
     * @param data      a data to put into elementData
     * @version         1.0
     */
    void push(T data) {
        if (size < capacity) {
            elementData[size] = data;
            size++;
        } else if (size == capacity) {
            expandCapacity();
            elementData[size] = data;
            size++;
        } else {
            throw std::out_of_range("in\"ArrayList::add\",size beyond capacity:this arraylist is no longer secure");
        }
    }

    /**
     * pop a data
     * @param index     index which contains the data wanted to erase
     * @version         1.0
     */
    T pop() {
        T temp = elementData[size - 1];
        size--;
        reduceCapacity();
        return temp;
    }

    /**
     * find first index of a data in array "elementData",if it
     * is not found,return -1 instead.
     * @param data      a data that wanted its index
     * @return          first index of the data in array "elementData"
     * @version         1.0
     */
    int indexOf(T data) {
        for (int i = 0; i < size; i++) {
            if (elementData[i] == data) {
                return i;
            }
        }
        return -1;
    }

    /**
     * find last index of a data in array "elementData",if it
     * is not found,return -1 instead.
     * @param data      a data that wanted its index
     * @return          first index of the data in array "elementData"
     * @version         1.0
     */
    int lastIndexOf(T data) {
        for (int i = size - 1; i >= 0; i--) {
            if (elementData[i] == data) {
                return i;
            }
        }
        return -1;
    }

    /**
     * return a value in array "elementData" by offering its index
     * @param index     value want to get
     * @return          value of this designated index
     * @version         1.0
     */
    T valueOf(int index) {
        if (index >= size) {
            throw std::overflow_error("in\"ArrayList::valueOf\",invalid index:index beyond capacity");
        } else {
            return elementData[index];
        }
    }

    /**
     * get the amount of real data that stored in array "elementData"
     * @return      size of an ArrayList
     * @version     1.0
     */
    int length() {
        return size;
    }

    /**
     * get the real size of array "elementData".
     * This function is mainly use to debug.
     * @return      size of array "elementData"
     * @version     1.0
     */
    int getCapacity() {
        return capacity;
    }

    /**
     * transfer ArrayList into standard array in cpp
     * @return      data in array form
     * @version     1.0
     */
    T *toArray() {
        auto *temp = new T[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = elementData[i];
        }
        return temp;
    }
};