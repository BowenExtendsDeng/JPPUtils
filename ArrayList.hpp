/**
 * @brief  a java like dynamic array impl by cpp
 * @author BowenDeng
 * @date 2021/1/18
 * @version 1.0 <p> impl a dynamic array with add, insert, update, remove... methods </p>
 * @version 1.1 <p> 2021/1/19
 *              <p> add one parameter constructor to ArrayList.Now developers can create
 *                  an instance by passing an cpp array </p>
 */
#pragma once
#include "List.hpp"

/**
 * @brief  a java like dynamic array impl by cpp
 *
 * @tparam T type of data that to store
 */
template<class T>
class ArrayList : public List<T>{
private:
    /**
     * capacity of array "element data" when it is created by
     * no-argument constructor
     * @version 1.0
     */
    const static int DEFAULT_CAPACITY = 10;
    /**
     * bound of array "element data"
     * @version 1.0
     */
    int capacity{};
    /**
     * number of valid data stored in array "element data"
     * @version 1.0
     */
    int size = 0;
    /**
     * real place to store data
     * @version 1.0
     */
    T *elementData;

    /**
     * expand capacity of array "elementData". It grows 1.5
     * times than before everytime it reaches to the bound.
     * @version 1.0
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
     * @version 1.0
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
     * @version 1.0
     */
    ArrayList<T>() {
        capacity = DEFAULT_CAPACITY;
        this->elementData = new T[DEFAULT_CAPACITY];
    }

    /**
     * initialize dynamic array with a specific size
     * @param initialCapacity initial capacity of array
     * "elementData".
     * It should be above zero
     * @version 1.0
     */
    explicit ArrayList<T>(int initialCapacity) {
        if (initialCapacity > 0) {
            capacity = initialCapacity;
            this->elementData = new T[initialCapacity - 1];
        } else {
            throw std::underflow_error("initial capacity should beyond zero");
        }
    }

    /**
     * initialize dynamic array by a cpp array.capacity and
     * * size will be update to the same as the size of parsed
     * array
     * @param array a cpp array to parse into ArrayList
     * @param length length of the passing array
     * @version 1.1
     */
    explicit ArrayList<T>(T array[],int length) {
        elementData = new T[length];
        for (int i = 0; i < length; ++i) {
            elementData[i] = array[i];
        }
        capacity = length;
        size = length;
    }

    /**
     * free memory of array "elementData"
     * @version 1.0
     */
    ~ArrayList() { delete elementData; }

    /**
     * add a new element into array "elementData".Also expand
     * elementData by calling expandCapacity when it finds that
     * size is equal to capacity
     * @param data a data to put into elementData
     * @version 1.0
     */
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

    /**
     * insert a data into a designated place by giving its index.
     * Origin data in this index and after this index will move
     * backward by one index.
     * @param index a index that wanted to put data in
     * @param data a data intended to break in array "elementData"
     * @version 1.0
     */
    void insert(int index, T data) {
        if (index > size) {
            throw std::out_of_range("invalid index:index beyond capacity");
        } else if (index < 0) {
            throw std::underflow_error("index should equals or beyond zero");
        } else {
            add(elementData[size - 1]);
            for (int i = size - 2; i > index; --i) {
                elementData[i] = elementData[i - 1];
            }
            elementData[index] = data;
        }
    }

    /**
     * update a data by a designated index
     * @param index index of update wanted data
     * @param data data wanted to update
     * @version 1.0
     */
    void update(int index, T data) {
        elementData[index] = data;
    }

    /**
     * remove a data by its index
     * @param index index which contains the data wanted to erase
     * @version 1.0
     */
    void remove(int index) {
        if (index > size) {
            throw std::overflow_error("invalid index:index beyond capacity");
        }
        for (int i = index; i < size; ++i) {
            elementData[i] = elementData[i + 1];
        }
        size--;
        reduceCapacity();
    }

    /**
     * find first index of a data in array "elementData",if it
     * is not found,return -1 instead.
     * @param data a data that wanted its index
     * @return first index of the data in array "elementData"
     * @version 1.0
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
     * @param data a data that wanted its index
     * @return first index of the data in array "elementData"
     * @version 1.0
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
     * @param index value want to get
     * @return value of this designated index
     * @version 1.0
     */
    T valueOf(int index) {
        if (index >= size) {
            throw std::overflow_error("invalid index:index beyond capacity");
        } else {
            return elementData[index];
        }
    }

    /**
     * get the amount of real data that stored in array "elementData"
     * @return size of an ArrayList
     * @version 1.0
     */
    int length() {
        return size;
    }

    /**
     * get the real size of array "elementData".
     * This function is mainly use to debug.
     * @return size of array "elementData"
     * @version 1.0
     */
    int getCapacity() {
        return capacity;
    }

    /**
     * transfer ArrayList into standard array in cpp
     * @return data in array form
     * @version 1.0
     */
    T *toArray() {
        auto *temp = new T[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = elementData[i];
        }
        return temp;
    }
};