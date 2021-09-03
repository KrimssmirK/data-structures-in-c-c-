#include <iostream>
#include <string>

using namespace std;

const int NO_OF_QUIZZES = 5;
const int PASSING_SCORE = 80;

double getAverage(int scores[]){
    int total = 0;
    for(int i = 0 ; i < NO_OF_QUIZZES; i++){
        total += scores[i];
    }
    double average = static_cast<double>(total) / NO_OF_QUIZZES;
    return average;
}

string showStatus(int score){
    if(score >= PASSING_SCORE){
        return "PASSED";
    }
    return "FAILED";
}

int main(){
    int scores[NO_OF_QUIZZES];
    for(int i = 0; i < NO_OF_QUIZZES; i++){
        cout << "Student " << (i + 1) << ": ";
        cin >> scores[i];
    }
    double average = getAverage(scores);
    cout << "The average is: " << average << endl << endl;
    for(int i = 0; i < NO_OF_QUIZZES; i++){
        
        cout << "Student " << (i + 1) << " -> " << showStatus(scores[i]) << "(" << scores[i] << ")" << endl;
    }
    cout << "The passing score is: " << PASSING_SCORE << endl;
    return 0;
}