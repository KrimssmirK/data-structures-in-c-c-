#include <iostream>

using namespace std;

const int SIZE_OF_ARRAY = 10;
const int UP_TO_FIFTH = 5;

int* MyFunction(int *ptr){
    for(int i = 0; i < UP_TO_FIFTH; i++){
        cout << "address of " << "element " << i + 1 << " " << ptr + i << endl;
    }
    int *address_fifth_element = ptr + 4;
    return address_fifth_element;
}

int main(){
    int array[SIZE_OF_ARRAY];
    int *q = MyFunction(array);
    cout << "address of 5th element: " << q << endl;
    return 0;
}