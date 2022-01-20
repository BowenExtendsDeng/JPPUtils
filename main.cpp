#include <iostream>

#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "Sort.hpp"

using namespace std;

int main() {
    auto testList = new ArrayList<int>();
    testList->add(1);
    testList->add(2);
    testList->add(5);
    testList->add(4);
    testList->add(3);

    testList->insert(0,9);
    testList->insert(5,8);

     bubbleSort(*testList, false);

    for (int i = 0; i < testList->length(); i++) {
        cout<<testList->valueOf(i)<<",";
    }
}

