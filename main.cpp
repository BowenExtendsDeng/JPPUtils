#include <iostream>

#include "ArrayList.hpp"
#include "LinkedList.hpp"

using namespace std;

int main(){
    auto *testList = new ArrayList<int>();
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(9);
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(5);
    testList->add(3);
    testList->add(5);
    cout<<testList->indexOf(5)<<endl;
    cout<<testList->valueOf(1)<<endl;

    for (int i = 0; i < testList->length(); ++i) {
        cout<<testList->valueOf(i)<<",";
    }
    cout<<endl;

    testList->remove(5);

    for (int i = 0; i < testList->length(); ++i) {
        cout<<testList->valueOf(i)<<",";
    }
    cout<<endl;

    cout<<testList->length()<<endl;

    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);
    testList->remove(0);

    for (int i = 0; i < testList->length(); ++i) {
        cout<<testList->valueOf(i)<<",";
    }
    cout<<endl;

    cout<<testList->length();
};

