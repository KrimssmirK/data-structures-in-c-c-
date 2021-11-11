#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    for(int i = 0; i < 10 ; i++){
        if(i == 4){
            i = 9;
        }
        cout << i << endl;
    }

    return 0;
}