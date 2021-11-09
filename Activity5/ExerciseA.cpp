#include <iostream>
#include <string>

const int N = 5;

using namespace std;

void Swap(int i, int j, string *lastNames){
    string temp = lastNames[i];
    lastNames[i] = lastNames[j];
    lastNames[j] = temp;

}

int SelectionSort(string *lastNames){
    int numberOfComparisons = 0;
    for(int i = 0 ; i < N - 1; i++){
        int minIdx = i;
        for(int j = i + 1 ; j < N ; j++){
            if(lastNames[minIdx] > lastNames[j]){
                minIdx = j;
            }
            numberOfComparisons++;
        }
        Swap(i, minIdx, lastNames);
    }
    return numberOfComparisons;
}

int BinarySearch(string target, string *lastNames, int *noOfComparisons){
    int firstIdx = 0;
    int secondIdx = N - 1;
    while(firstIdx < secondIdx){
        (*noOfComparisons)++;
        int middleIdx = (firstIdx + secondIdx) / 2;

        if(lastNames[middleIdx] == target){
            return middleIdx;
        }else if(lastNames[middleIdx] < target){
            firstIdx = middleIdx;
        }else{
            secondIdx = middleIdx;
        }

        
    }
    return -1;
}

int main(){
    string lastNames[N];
  
    lastNames[0] = string("sugino");
    lastNames[1] = string("London");
    lastNames[2] = string("Dizon");
    lastNames[3] = string("Magtibay");
    lastNames[4] = string("Garcia");

    int numberOfComparisonsInSorting = SelectionSort(lastNames);

    cout << "number of comparisons in sorting algorithm: " << numberOfComparisonsInSorting << endl;

    string lookFor;
    cout << "looking for? ";
    cin >> lookFor;

    int numberOfComparisonsInBinarySearch = 0;
    int idx = BinarySearch(lookFor, lastNames, &numberOfComparisonsInBinarySearch);

    cout << lookFor << " is in index = " << idx << endl;
    cout << "number of comparisons in binary search: " << numberOfComparisonsInBinarySearch << endl;

    return 0;
}