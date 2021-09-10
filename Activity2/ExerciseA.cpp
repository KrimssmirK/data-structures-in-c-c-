#include <iostream>

using namespace std;

const int SIZE_OF_ARRAY = 5;

int* MyFunction(int *ptr){
    cout << "address of 1st element: " << ptr << endl;
    int *address_fifth_element = ptr + 4;
    return address_fifth_element;
}

int main(){
    int array[SIZE_OF_ARRAY];
    int *q = MyFunction(array);
    cout << "address of 5th element: " << q << endl;
    return 0;
}