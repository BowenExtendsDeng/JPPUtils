#include <iostream>

#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "Sort.hpp"

using namespace std;

int main() {
    auto testList = new LinkedList<int>();
    testList->add(1);
    testList->add(2);
    testList->add(5);
    testList->add(4);
    testList->add(3);
    testList->add(6);

    testList->insert(0,9);
    testList->insert(5,8);

     bubbleSort(*testList, true);

    for (int i = 0; i < testList->length(); i++) {
        cout<<testList->valueOf(i)<<",";
    }
}

