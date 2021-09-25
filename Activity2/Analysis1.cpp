#include <iostream>

using namespace std;

const int SIZE_OF_ARRAY = 5;

int main()
{
    int a[SIZE_OF_ARRAY];
    char b[SIZE_OF_ARRAY];
    double c[SIZE_OF_ARRAY];

    cout << "The addresses of the int[] is:\n";
    for(int i = 0; i <= SIZE_OF_ARRAY; i++){
       printf("%d\n", &a[i]);
        
    }
    cout << "The addresses of the char[] is:\n";
    for(int i = 0; i <= SIZE_OF_ARRAY; i++){
       printf("%d\n", &b[i]);
    }        
    
    cout << "The addresses of the double[] is:\n";
    for(int i = 0; i <= SIZE_OF_ARRAY; i++){
       printf("%d\n", &c[i]);        
    }
}