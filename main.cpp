#include <iostream>

#include "ArrayList.hpp"
#include "LinkedList.hpp"

using namespace std;

int main() {
    int test[40] = {1,2,3,4,5,6,7,8,9,0,
                    1,2,3,4,5,6,7,8,9,0,
                    1,2,3,4,5,6,7,8,9,0,
                    1,2,3,4,5,6,7,8,9,0};
    auto *testList = new ArrayList<int>(test,40);
    cout << testList->indexOf(5) << endl;
    cout << testList->valueOf(1) << endl;

    for (int i = 0; i < testList->length(); ++i) {
        cout << testList->valueOf(i) << ",";
    }
    cout << endl;

    testList->remove(5);

    for (int i = 0; i < testList->length(); ++i) {
        cout << testList->valueOf(i) << ",";
    }
    cout << endl;

    cout << testList->length() << endl;

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
        cout << testList->valueOf(i) << ",";
    }
    cout << endl;

    testList->insert(1, 99);

    for (int i = 0; i < testList->length(); ++i) {
        cout << testList->valueOf(i) << ",";
    }
    cout << endl;

    cout << testList->length();
};

