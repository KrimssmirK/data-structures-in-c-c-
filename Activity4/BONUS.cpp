#include <iostream>

using namespace std;

int main(){
    cout << "enter the size of pyramid: ";
    int size_of_pyramid;
    cin >> size_of_pyramid;
    for(int i = 0; i < size_of_pyramid ; i++){
        char c = 65 + i;
        for(int j = 0 ; j < i + 1 ; j++){
            cout << c;
        }
        cout << endl;
    }
}