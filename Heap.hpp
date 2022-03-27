/**
 * @brief           heap impl by arraylist, first index of a heap is: 1
 * @author          BowenDeng
 * @date            2021/1/19
 * @version 1.0 <p>  </p>
 */

#pragma once
#include "ArrayList.hpp"
#include <stdexcept>

template<class T>
class Heap {
private:
    /**
     * place to store data
     * @version         1.0
     */
    ArrayList<T> *elementData = new ArrayList<T>();

    /**
     *
     * @param index
     * @return
     */
    int leftIndex(int index){
        index *= 2;
        if(index > length()){
            throw std::out_of_range("in\"Heap::leftIndex\",invalid index:index*2 beyond capacity");
        }else if(index < 1) {
            throw std::underflow_error("in\"Heap::leftIndex\",index should equals or beyond zero");
        }else {
            return index;
        }
    }

    /**
     *
     * @param index
     * @return
     */
    int rightIndex(int index){
        index = index * 2 + 1;
        if(index > length()){
            throw std::out_of_range("in\"Heap::rightIndex\",invalid index:index*2+1 beyond capacity");
        }else if(index < 1) {
            throw std::underflow_error("in\"Heap::rightIndex\",index should equals or beyond zero");
        }else {
            return index;
        }
    }

    /**
     *
     * @param index
     * @return
     */
    int parentIndex(int index){
        index /= 2;
        if(index > length()){
            throw std::out_of_range("in\"Heap::parentIndex\",invalid index:index/2 beyond capacity");
        }else if(index < 1) {
            throw std::underflow_error("in\"Heap::parentIndex\",index should equals or beyond zero");
        }else if(index == 1){
            return -1;
        }else {
            return index;
        }
    }

    /**
     *
     * @param index
     * @return
     */
    T left(int index){
        index = leftIndex(index);
        return elementData->valueOf(index - 1);
    }

    /**
     *
     * @param index
     * @return
     */
    T right(int index){
        index = rightIndex(index);
        return elementData->valueOf(index - 1);
    }

    /**
     *
     * @param index
     * @return
     */
    T parent(int index){
        index = parentIndex(index);
        return elementData->valueOf(index - 1);
    }

    /**
     *
     */
    void buildMaxHeap(){
        for(int i = length()/2; i > 0; i /= 2){
            maxHeapify(i);
        }
    }

public:
    /**
     *
     * @param srcList
     */
    explicit Heap(ArrayList<T> srcList){
        elementData = srcList;
        buildMaxHeap();
    }

    /**
     *
     * @param array
     * @param length
     */
    Heap(T array[],int length){
        elementData = new ArrayList<T>(array, length);
        buildMaxHeap();
    }

    /**
     *
     * @param index
     */
    void maxHeapify(int index){
        int leftChildIndex;
        int rightChildIndex;
        int largestIndex = index;
        if ((index * 2 + 1) < elementData->length()){
            leftChildIndex = this->leftIndex(index);
            rightChildIndex = this->rightIndex(index);
        }
        if(elementData->valueOf(index - 1) < elementData->valueOf(leftChildIndex - 1)){
            largestIndex = leftChildIndex;
        }
        if(elementData->valueOf(largestIndex - 1) < elementData->valueOf(rightChildIndex - 1)){
            largestIndex = rightChildIndex;
        }
        if(largestIndex != index){
            elementData->swap(largestIndex - 1, index - 1);
            maxHeapify(largestIndex);
        }
    }

    /**
     *
     */
    void maxHeapify(){
        maxHeapify(1);
    }

    /**
     *
     * @param temp
     * @return
     */
    int indexOf(T temp){
        return elementData->indexOf(temp) + 1;
    }

    /**
     *
     * @param index serial number of a designated element in the heap
     * @return value of element of a designated index in the heap
     */
    T valueOf(int index){
        return elementData->valueOf(index - 1);
    }

    /**
     * show length of a heap
     * @return size of a heap
     */
    int length(){
        return elementData->length();
    }

    void swap(int index1, int index2){
        elementData->swap(index1 - 1, index2 - 1);
    }
};