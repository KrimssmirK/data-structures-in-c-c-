#include <iostream>

using namespace std;

double getGPA(int score){
    if(score >= 96){
        return 4.00;
    }else if(score >= 90){
        return 3.50;
    }else if(score >= 84){
        return 3.00;
    }else if(score >= 78){
        return 2.50;
    }else if(score >= 72){
        return 2.00;
    }else if(score >= 66){
        return 1.50;
    }else if(score >= 60){
        return 1.00;
    }else{
        return 0.00;
    }
}

int main(){
    int score;
   
    while(true){
        cout << "score: ";
        cin >> score;
        cout << "GPA: " << getGPA(score) << endl;
    }
    return 0;
}