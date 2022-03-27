/**
 * @brief           heap impl by list defined in this project, first index of a heap is: 1
 * @author          BowenDeng
 * @date            2021/1/19
 * @version 1.0 <p>  </p>
 */

#pragma once
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include <stdexcept>

template<class T>
class Heap {
private:
    /**
     * place to store data
     * @version         1.0
     */
    List<T> *elementData;

    /**
     * method to give left side index of a input index
     * @param index index to find its left branch
     * @return left index of this index
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
     * method to give right side index of a input index
     * @param index index to find its right branch
     * @return right index of this index
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
     * method to give parent side index of a input index
     * @param index index to find its parent branch
     * @return parent index of this index
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
     * method to give left side value of a input index
     * @param index index to find its left branch
     * @return left side value of this index
     */
    T left(int index){
        index = leftIndex(index);
        return elementData->valueOf(index - 1);
    }

    /**
     * method to give right side value of a input index
     * @param index index to find its right branch
     * @return right side value of this index
     */
    T right(int index){
        index = rightIndex(index);
        return elementData->valueOf(index - 1);
    }

    /**
     * method to give parent value of a input index
     * @param index index to find its parent branch
     * @return parent side value of this index
     */
    T parent(int index){
        index = parentIndex(index);
        return elementData->valueOf(index - 1);
    }

    /**
     * method to build a max heap
     */
    void buildMaxHeap(){
        for(int i = length()/2; i > 0; i /= 2){
            maxHeapify(i);
        }
    }

public:
    /**
     * instantiate a Heap class by transforming a list into a heap
     * @param srcList a list to convert into a heap
     */
    explicit Heap(List<T> srcList){
        elementData = srcList;
        buildMaxHeap();
    }

    /**
     * instantiate a Heap class by transforming an array into a heap
     * @param array an array to convert into a heap
     * @param length length of this input array
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