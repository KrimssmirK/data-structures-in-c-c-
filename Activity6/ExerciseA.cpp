// library used
#include <iostream>
#include <string>

// namespace used
using namespace std;

//constant values
const int PREFIX = 1;
const int POSTFIX = 2;
const int INFIX = 3;

//my functions
int GetId(string expression);
void Prefix();
void Postfix();
void Infix();


int main(){
    bool isWrongExpression;
    do{
        isWrongExpression = false;
        cout << "Enter a notation:";
        string expression;
        cin >> expression;
        switch(GetId(expression)){
            case PREFIX:
                Prefix();
                break;
            case POSTFIX:
                Postfix();
                break;
            case INFIX:
                Infix();
                break;
            default:
                cout << "wrong expression\t TRY AGAIN!" << endl;
                isWrongExpression = true;
        }
    }while(isWrongExpression);
    
    return 0;
}

int GetId(string expression){
    // change all string's case in upper case
    for(int i = 0; i < expression.length(); i++){
        expression[i] = toupper(expression[i]);
    }
    //////////////////////////////////////////

    if(expression.compare("PREFIX") == 0){
        return PREFIX;
    }else if(expression.compare("POSTFIX") == 0){
        return POSTFIX;
    }else if(expression.compare("INFIX") == 0){
        return INFIX;
    }
    return 0;
}


// solutions
void Prefix(){
    cout << "calculating in prefix mode..." << endl;
}
void Postfix(){
    cout << "calculating in postfix mode..." << endl;
}
void Infix(){
    cout << "calculating in Infix mode..." << endl;
}
