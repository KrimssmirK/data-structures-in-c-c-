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
bool isOperand(char c);
int Perform(char op, int operand1, int operand2);
string InfixToPostfix(string exp);
bool hasGreaterPrecedence(char c1, char c2);
bool isClosingParanthesis(char c);
bool isOpeningParanthesis(char c);



int main(){
    int answer = 0;
    bool isWrongNotation;
    do{
        isWrongNotation = false;
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
                cout << "wrong notation\t TRY AGAIN!" << endl;
                isWrongNotation = true;
        }
    }while(isWrongNotation);
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
    stack<int> stack;
    for(int i = exp.length() - 1; i >= 0; i--){
        if(isOperator(exp[i])){
            int op1 = stack.top(); stack.pop();
            int op2 = stack.top(); stack.pop();
            int res = Perform(exp[i], op1, op2);
            stack.push(res);
            i--;
        }else{
            string numString = "";
            while(exp[i] != ' '){
                numString = exp[i--] + numString;
            }
            stack.push(stoi(numString));
        }
    }
    return stack.top();
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
    string res = InfixToPostfix(exp);
    return Postfix(res);
}

bool isOperand(char c){
    char nums[] = {'0','1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i < sizeof(nums)/sizeof(char); i++){
        if(c == nums[i]){
            return true;
        } 
    }
    return false;
}

bool isOpeningParanthesis(char c){
    return c == '(';
}

bool isClosingParanthesis(char c){
    return c == ')';
}

bool hasGreaterPrecedence(char c1, char c2){
    if(c1 == '*' || c1 == '/'){
        return c2 == '+' || c2 == '-';
    }
    if(c1 == '+' || c1 == '-'){
        return c2 == '+' || c2 == '-';
    }
    return false;
}

string InfixToPostfix(string exp){
    string res = "";
    stack<char> stack;
    for(int i = 0; i < exp.length(); i++){
        if(isOperand(exp[i])){
            res = res + exp[i];
        }else if(isOperator(exp[i])){
            bool flag;
            while( (flag = !stack.empty() && hasGreaterPrecedence(stack.top(), exp[i]) && !isClosingParanthesis(stack.top())) ){
                res = res + ' ' + stack.top();
                stack.pop();
            }
            if(!flag){
                res = res + ' ';
            }
            stack.push(exp[i]);
        }else if(isOpeningParanthesis(exp[i])){
            stack.push(exp[i]);
        }else if(isClosingParanthesis(exp[i])){
            while(!stack.empty() && !isOpeningParanthesis(stack.top())){
                res = res + ' ' + stack.top();
                stack.pop();
            }
            stack.pop();
        }
    }
    while(!stack.empty()){
        res = res + ' ' + stack.top();
        stack.pop();
    }
    return res;
}
