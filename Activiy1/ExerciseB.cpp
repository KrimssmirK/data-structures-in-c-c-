#include <iostream>

using namespace std;

int main(){
    int score;
    int total = 0;
    int count = 0;
    double current_average;
    while(true){
        count++;
        cout << "score: ";
        cin >> score;
        total += score;
        current_average = double(total / count);
        cout << "Running Average is: " << current_average << endl;
    }
    return 0;
}