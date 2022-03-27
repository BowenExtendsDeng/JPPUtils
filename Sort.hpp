/**
 * @brief   various sort algorithm impl by java like
 *          cpp data structure
 * @author BowenDeng
 * @date 2021/1/19
 * @version 1.0 <p> finish insertionSort, bubbleSort, selectionSort </p>
 */

#pragma once

#include "ArrayList.hpp"
#include "LinkedList.hpp"

/**
 * @brief           insertion sort
 * @warning         only LinkedList and ArrayList can be passed in.Some type
 *                  such as String or Char are not recommended to sort
 * @tparam T        type of data wanted to sort.
 * @param srcList   a sort wanted list
 * @param ascending true mains the list will will be sorted in ascending order.
 *                  false mains the list will will be sorted in descending order
 * @return          sorted list in LinkedList form
 * @version 1.0
 */
template<typename T>
void insertionSort(List<T> &srcList,bool ascending){
    auto *dstList = new LinkedList<T>();
    dstList->add(srcList.valueOf(0));
    for (int i = 1; i < srcList.length(); i++) {
        for (int j = 0; j < i + 1; ++j) {
            if (ascending && srcList.valueOf(i) < dstList->valueOf(j)) {
                dstList->insert(j, srcList.valueOf(i));
                break;
            }
            if ((!ascending) && srcList.valueOf(i) > dstList->valueOf(j)) {
                dstList->insert(j, srcList.valueOf(i));
                break;
            }
            if (j == i) {
                dstList->add(srcList.valueOf(i));
                break;
            }
        }
    }
    for (int i = 0; i < dstList->length(); ++i) {
        srcList.update(i,dstList->valueOf(i));
    }
    delete dstList;
}

/**
 * @brief           bubble sort
 * @warning         only LinkedList and ArrayList can be passed in.Some type
 *                  such as String or Char are not recommended to sort
 * @tparam T        type of data wanted to sort.
 * @param srcList   a sort wanted list
 * @param ascending true mains the list will will be sorted in ascending order.
 *                  false mains the list will will be sorted in descending order
 * @return          sorted list in LinkedList form
 * @version 1.0
 */
template<typename T>
void bubbleSort(List<T> &srcList,bool ascending){

    for (int i = 0; i < srcList.length() - 1; i++) {
        for (int j = i; j < srcList.length(); ++j) {
            if(ascending && srcList.valueOf(i) > srcList.valueOf(j)){
                T temp = srcList.valueOf(i);
                srcList.update(i,srcList.valueOf(j));
                srcList.update(j, temp);
            }

            if ((!ascending) && srcList.valueOf(i) < srcList.valueOf(j)) {
                T temp = srcList.valueOf(i);
                srcList.update(i,srcList.valueOf(j));
                srcList.update(j, temp);
            }
        }
    }
}

/**
 * @brief           selection sort
 * @warning         only LinkedList and ArrayList can be passed in.Some type
 *                  such as String or Char are not recommended to sort
 * @tparam T        type of data wanted to sort.
 * @param srcList   a sort wanted list
 * @param ascending true mains the list will will be sorted in ascending order.
 *                  false mains the list will will be sorted in descending order
 * @return          sorted list in LinkedList form
 * @version 1.0
 */
template<typename T>
void selectionSort(List<T> &srcList,bool ascending){
    for (int i = 0; i < srcList.length() - 1; i++) {
        int minOrMaxIndex = i;
        for (int j = i + 1; j < srcList.length(); j++) {
            if(ascending && (srcList.valueOf(minOrMaxIndex) > srcList.valueOf(j))){
                minOrMaxIndex = j;
            }
            if ((!ascending) && (srcList.valueOf(minOrMaxIndex) < srcList.valueOf(j))) {
                minOrMaxIndex = j;
            }
        }
        if(minOrMaxIndex != i){
            T temp = srcList.valueOf(i);
            srcList.update(i,srcList.valueOf(minOrMaxIndex));
            srcList.update(minOrMaxIndex, temp);
        }
    }
}

#include "Heap.hpp"

/**
 * @brief           heap sort
 * @tparam T        a sort wanted list
 * @param heap      a sort-wanted heap
 * @return          sorted heap
 * @version 1.0
 */
template <typename T>
void heapSort(Heap<T> heap){
    int heapSize = heap.length();
    for(int i = heap.length(); i > 1; i /= 2){
        heap.swap(1, i);
        heapSize -= 1;
        heap.maxHeapify();
    }
    return heap;
}
