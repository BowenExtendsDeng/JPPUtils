/**
 * @brief           a java like list impl by cpp
 * @author          BowenDeng
 * @date            2021/1/19
 * @version 1.0 <p> define all methods that various lists have in common </p>
 */

#pragma once

/**
 * interface of all Lists including stack and queue.
 * In List.hpp some basic methods are defined here.
 * @tparam T    data intended to be stored
 */
template<class T>
class List {
private:
    /**
     * number of a type of data stored in list
     */
    int size = 0;
public:
    /**
     * @brief       add a data at the end of the list.
     * @warning     this method must be override
     * @param data  data to put at the end of the list
     */
    virtual void add(T data) = 0;

    /**
     * @brief update a data into the list.stack and queue should not calling this method
     * @param data      new data to update
     * @param index     index of deprecated data to erase
     */
    virtual void update(int index, T data) {}

    /**
     * @brief insert a data into the list.stack and queue should not calling this method
     * @param data      new data to insert
     * @param index     index of deprecated data to erase
     */
    virtual void insert(int index, T data) {}

    /**
     * remove a data found by its index from the list
     * @warning this method must be override
     * @param index     index of the data wanted to be erased
     */
    virtual void remove(int index) = 0;

    /**
     * getting first index of a data.If nothing
     * found in the list, returns -1.
     * @warning     this method must be override
     * @param data  data wanted to find its first index
     * @return      first index of this data.
     */
    virtual int indexOf(T data) = 0;

    /**
     * getting last index of a data.If nothing
     * found in the list, returns -1.
     * @warning     this method must be override
     * @param data  data wanted to find its last index
     * @return      last index of this data.
     */
    virtual int lastIndexOf(T data) = 0;

    /**
     * getting data of a index.If nothing
     * found in the list, returns a nullptr.
     * @warning     this method must be override
     * @param data  data wanted to find its first index
     * @return      first index of this data.
     */
    virtual T valueOf(int index) = 0;

    /**
     * parsing a List into cpp array
     * @warning     this method must be override
     */
    virtual T *toArray() = 0;

    /**
     * get length of a list
     * @warning     this method must be override
     * @return      length of this List
     */
    virtual int length() = 0;
};

