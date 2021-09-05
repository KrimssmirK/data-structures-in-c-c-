#include <iostream>
#include <string>

using namespace std;

void showNoOfAppearance(string input){
    cout << "Number of appearances" << endl;
    for(int i = 0 ; i < input.length() ; i++){
        char current_char = input[i];
        if(current_char == '\0' || current_char == ' '){
            continue;
        }
        int count = 0;
        for(int j = 0 ; j < input.length() ; j++){
            if(input[j] == current_char){
                count++;
                input[j] = '\0';
            }
        }
        cout << current_char << " -> " << count << endl;
    }
    cout << endl;
}

void showIndices(string input){
    cout << "Indices of the character" << endl;
    for(int i = 0 ; i < input.length() ; i++){
        char current_char = input[i];
        if(current_char == '\0' || current_char == ' '){
            continue;
        }
        cout << current_char << " -> ";
        for(int j = 0 ; j < input.length() ; j++){
            if(input[j] == current_char){
                cout << j << " ";
                input[j] = '\0';
            }
        }
        cout << endl;
    }
    cout << endl;
}



void changeStringToCharArray(char *c, string input){
    for(int i = 0 ; i < input.length(); i++){
        *c = input[i];
        c++;
    }
    *c = '\0';
}

int main(){
    string input;
    cout << "Enter characters: ";
    getline(cin, input);

    showNoOfAppearance(input);
    
    showIndices(input);
    
    
    return 0;
}