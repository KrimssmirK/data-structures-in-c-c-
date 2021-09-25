#include <iostream>
#include "MyQuickSort.h"

using namespace std;

void PrintSubArray(int *sub_array, int size){
    cout << "[";
    for(int i = 0; i < size; i++){
        cout << sub_array[i] << ",";
    }
    cout << "]" << endl;
}

void Merge(int *left, int left_size, int *right, int right_size, int *array){
    int k = 0, i = 0, j = 0;
    while(i < left_size && j < right_size){
        if(left[i] <= right[j]){
            array[k++] = left[i++];
        }else{
            array[k++] = right[j++];
        }
    }
    while(i < left_size){
        array[k++] = left[i++];
    }
    while(j < right_size){
        array[k++] = right[j++];
    }
}

void MergeSort(int *array, int size){
    if(size < 2) return;
    //initializing new sub arrays
    int middle = size / 2;
    int left_size = middle;
    int right_size = size - middle;
    int left[left_size];
    int right[right_size];
    for(int i = 0; i < middle; i++){
        left[i] = array[i];
    }
    for(int i = middle; i < size; i++){
        right[i - middle] = array[i];
    }
    //to show the process of dividing
    cout << "dividing ";
    PrintSubArray(array, size);
    cout << endl;
    cout << "left";
    PrintSubArray(left, left_size);
    cout << " and right";
    PrintSubArray(right, right_size);
    cout << endl;

    MergeSort(left, left_size);
    MergeSort(right, right_size);

    //to show the process of merging
    cout << "merging left";
    PrintSubArray(left, left_size);
    cout << " and right";
    PrintSubArray(right, right_size);
    cout << endl;

    //merging
    Merge(left, sizeof(left)/sizeof(int), right, sizeof(right)/sizeof(int), array);

    //to show the data after merging
    cout << "merged";
    PrintSubArray(array, size);
    cout << endl;
    
}

int main(){
    int data[] = {12,11,13,5,6,7};
    // MergeSort(data, sizeof(data)/sizeof(int));
    QuickSort(data, 0, sizeof(data)/sizeof(int) - 1);

    for(int i = 0 ; i < sizeof(data)/sizeof(int); i++){
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}