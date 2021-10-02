#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;



int main(){
    int array[] = {1,2,3,4,5,6,7,8};
    for(int i = 0 ; i < 8; i++){
        for(int j = 0 ; j < 8; j++){
            cout << array[j] << " ";
        }
    }
    cout << endl;
    

}
