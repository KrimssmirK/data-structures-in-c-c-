#include <iostream>
#include <string>

using namespace std;

int* MyFunction(int *p){
    cout << "The address of 1st element in the Array -> " << p << endl;
    return p + 4;
}

int main(){
    //declare array;
    int A[5];
    //declare pointer to get the address of 5th element in the A
    int *q;
    q = MyFunction(A);
    cout << "The address of 5th element in the Array -> " << q << endl;
}
