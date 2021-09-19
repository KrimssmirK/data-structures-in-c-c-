#include <iostream>
#include <string>

//number of inputs
const int N = 5;

using namespace std;

void Swap(int i, int j, string *lastNames){
    string temp = lastNames[i];
    lastNames[i] = lastNames[j];
    lastNames[j] = temp;

}

int BubbleSort(string *lastNames){
    int numberOfComparisons = 0;
    bool isSorted = false;
    int counter = 0;
    while(!isSorted){
        isSorted = true;
        for(int i = 0 ; i < N - 1 - counter ; i++){
            if(lastNames[i] > lastNames[i+1]){
                Swap(i, i+1, lastNames);
                isSorted = false;
            }
        }
        numberOfComparisons++;
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

    int numberOfComparisonsInSorting = BubbleSort(lastNames);

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