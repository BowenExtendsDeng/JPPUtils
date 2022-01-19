#pragma once

/**
 * @brief  a java like dynamic array impl by cpp
 *
 * @tparam T type of data that to store
 * @author BowenDeng
 * @date 2021/1/18
 * @version 1.0
 */
template<class T>
class ArrayList {
private:

    /**
     * capacity of array "element data" when it is created by
     * no-argument constructor
     */
    const static int DEFAULT_CAPACITY = 10;
    /**
     * bound of array "element data"
     */
    int capacity;
    /**
     * number of valid data stored in array "element data"
     */
    int size = 0;
    /**
     * real place to store data
     */
    T *elementData;

    /**
     * expand capacity when size reaches the bound. It grows
     * 1.5 times than before everytime it reaches to the bound.
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
     * will lose during this action.
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
     * none argument constructor of class ArrayList. It will allocate
     * an empty array size of 10.
     */
    ArrayList<T>() {
        capacity = DEFAULT_CAPACITY;
        this->elementData = new T[DEFAULT_CAPACITY];
    }

    /**
     * initialize dynamic array with a specific size
     * @param initialCapacity initial capacity of array "elementData".
     * It should be above zero
     */
    explicit ArrayList<T>(int initialCapacity) {
        if (initialCapacity > 0) {
            capacity = initialCapacity;
            this->container = new T[initialCapacity - 1];
        } else {
            throw std::underflow_error("initial capacity should beyond zero");
        }
    }

    ~ArrayList() { delete elementData; }

    void add(T data) {
        if (size < capacity) {
            elementData[size] = data;
            size++;
        } else if (size == capacity) {
            expandCapacity();
            elementData[size] = data;
            size++;
        } else {
            throw std::out_of_range("size beyond capacity:this arraylist is no longer secure");
        }
    }

    bool remove(int index) {
        if (index > size) {
            throw std::overflow_error("invalid index:index beyond capacity");
        }
        for (int i = index; i < size; ++i) {
            elementData[i] = elementData[i + 1];
        }
        size--;
        reduceCapacity();
    }

    int indexOf(T data) {
        for (int i = 0; i < size; i++) {
            if (elementData[i] == data) {
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(T data){
        for (int i = size - 1; i >= 0; i--) {
            if (elementData[i] == data) {
                return i;
            }
        }
        return -1;
    }

    T valueOf(int index) {
        if (index >= size) {
            throw std::overflow_error("invalid index:index beyond capacity");
        } else {
            return elementData[index];
        }
    }

    int length() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};