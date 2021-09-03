#include <iostream>

using namespace std;

void getScoreAndShowAverage(int *p_score, int *p_total, int *p_count, double *p_average){
        (*p_count)++;
        cout << "score: ";
        cin >> *p_score;
        *p_total += *p_score;
        *p_average = static_cast<double>(*p_total) / *p_count;
        cout << "Running Average is: " << *p_average << endl;
}

int main(){
    int score;
    int running_total = 0;
    int count = 0;
    double running_average;
    while(true){
        getScoreAndShowAverage(&score, &running_total, &count, &running_average);
    }
    return 0;
}