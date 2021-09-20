#include <iostream>
#include <string>

//number of inputs
const int N = 5;

using namespace std;

int InsertionSort(string *lastNames){
    int numberOfComparisons = 0;
    for(int i = 1; i < N ; i++){
        string currentLastName = lastNames[i];
        int hole = i;
        numberOfComparisons++;
        while(hole > 0 && lastNames[hole-1] > currentLastName){
            lastNames[hole] = lastNames[hole-1];
            hole--;
            numberOfComparisons++;
        }
        lastNames[hole] = currentLastName;
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

    lastNames[0] = string("Sugino");
    lastNames[1] = string("London");
    lastNames[2] = string("Dizon");
    lastNames[3] = string("Magtibay");
    lastNames[4] = string("Garcia");

    int numberOfComparisonsInSorting = InsertionSort(lastNames);

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