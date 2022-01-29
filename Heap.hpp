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
     * real place to store data
     * @version         1.0
     */
    ArrayList<T> *elementData = new ArrayList<T>();

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

    int parentIndex(int index){
        index /= 2;
        if(index > length()){
            throw std::out_of_range("in\"Heap::parentIndex\",invalid index:index/2 beyond capacity");
        }else if(index < 1) {
            throw std::underflow_error("in\"Heap::parentIndex\",index should equals or beyond zero");
        }else if(index == 1){
            throw std::invalid_argument("in\"Heap::parentIndex\",first index do not have a parent");
        }else {
            return index;
        }
    }

    T left(int index){
        index = leftIndex(index);
        return elementData->valueOf(index - 1);
    }

    T right(int index){
        index = rightIndex(index);
        return elementData->valueOf(index - 1);
    }

    T parent(int index){
        index = parentIndex(index);
        return elementData->valueOf(index - 1);
    }

    void buildMaxHeap(){
        for(int i = length()/2; i > 0; i /= 2){
            maxHeapify(i);
        }
    }
public:
    explicit Heap(ArrayList<T> srcList){
        elementData = srcList;
        buildMaxHeap();
    }

    Heap(T array[],int length){
        elementData = new ArrayList<T>(array, length);
        buildMaxHeap();
    }

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

    void maxHeapify(){
        maxHeapify(1);
    }

    int indexOf(T temp){
        return elementData->indexOf(temp) + 1;
    }

    T valueOf(int index){
        return elementData->valueOf(index - 1);
    }

    int length(){
        return elementData->length();
    }
};