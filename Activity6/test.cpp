#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1 = "pREFIX";
    
    boost:: to_upper(s1);

    cout << s1;

    return 0;
}