// library used
#include <iostream>
#include <string>
#include <stack>

// namespace used
using namespace std;

//constant values
const int PREFIX = 1;
const int POSTFIX = 2;
const int INFIX = 3;

//my functions
int GetId(string notation);
int Prefix(string exp);
int Postfix(string exp);
int Infix(string exp);
bool isOperator(char op);
int Perform(char op, int operand1, int operand2);



int main(){
    int answer = 0;
    bool isWrongExpression;
    do{
        isWrongExpression = false;
        cout << "Enter a notation: ";
        string notation;
        getline(cin, notation);
        cout << "Enter the expression: ";
        string expression;
        getline(cin, expression);
        switch(GetId(notation)){
            case PREFIX:
                answer = Prefix(expression);
                break;
            case POSTFIX:
                answer = Postfix(expression);
                break;
            case INFIX:
                answer = Infix(expression);
                break;
            default:
                cout << "wrong expression\t TRY AGAIN!" << endl;
                isWrongExpression = true;
        }
    }while(isWrongExpression);
    cout << "Answer: " << answer << endl;
    return 0;
}

int GetId(string notation){
    // change all string's case in upper case
    for(int i = 0; i < notation.length(); i++){
        notation[i] = toupper(notation[i]);
    }
    //////////////////////////////////////////

    if(notation.compare("PREFIX") == 0){
        return PREFIX;
    }else if(notation.compare("POSTFIX") == 0){
        return POSTFIX;
    }else if(notation.compare("INFIX") == 0){
        return INFIX;
    }
    return 0;
}


// solutions
int Prefix(string exp){
    cout << "calculating in prefix mode..." << endl;
    return 0;
}
int Postfix(string exp){
    stack<int> stack;
    for(int i = 0; i < exp.length(); i++){
        if(isOperator(exp[i])){
            int op2 = stack.top(); stack.pop();
            int op1 = stack.top(); stack.pop();
            int res = Perform(exp[i], op1, op2);
            stack.push(res);
            i++; // to prevent space error in Line 92
        }else{
            string numString = "";
            while(exp[i] != ' '){
                numString = numString + exp[i++];  
            }
            cout << "numString=" << numString << endl;
            stack.push(stoi(numString));  
        }
    }
    return stack.top();
}
int Perform(char op, int operand1, int operand2){
    if(op == '+'){
        return operand1 + operand2;
    }else if(op == '-'){
        return operand1 - operand2;
    }else if(op == '*'){
        return operand1 * operand2;
    }else if(op == '/'){
        return operand1 / operand2;
    }
    return 0;
}
bool isOperator(char op){
    return op == '+' || op == '-' || op == '*' || op == '/';
}
int Infix(string exp){
    cout << "calculating in Infix mode..." << endl;
    return 0;
}
