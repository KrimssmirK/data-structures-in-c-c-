#include <iostream>
#include <string>

using namespace std;

bool hasSeen(char c, char *ptr_c){
    while(*ptr_c != '\0'){
        if(*ptr_c == c){
            return true;
        }
        ptr_c++;
    }
    return false;
}

void showNoOfAppearances(char *c, int size){
    cout << "Number of appearances" << endl;
    char seen[size + 1];
    for(int i = 0 ; i < size ; i++){
        char current_char = c[i];
        if(hasSeen(current_char, seen) || current_char == ' '){
            continue;
        }
        int count = 0;
        for(int j = 0 ; j < size ; j++){
            if(c[j] == current_char){
                count++;
            }
        }
        cout << current_char << " -> " << count << endl;
        seen[i] = current_char;
    }
    if(seen[0] != c[0]){
        cout << "null";
    }
    cout << endl;
    
}

void showIndices(char *c, int size){
    cout << "Indices of the character" << endl;
    char seen[size + 1];
    for(int i = 0 ; i < size ; i++){
        char current_char = c[i];
        if(hasSeen(current_char, seen) || current_char == ' '){
            continue;
        }
        cout << current_char << " -> ";
        for(int j = 0 ; j < size ; j++){
            if(c[j] == current_char){
                cout << j << " ";
            }
        }
        cout << endl;
        seen[i] = current_char;
    }
    if(seen[0] != c[0]){
        cout << "null";
    }
    cout << endl;
}



void showAddress(char *c, int size){
    cout << "Addresses of the character" << endl;
    char seen[size + 1];
    for(int i = 0; i < size; i++){
        char current_char = c[i];
        if(hasSeen(current_char, seen) || current_char == ' '){
            continue;
        }
        cout << current_char << " -> ";
        for(int j = 0; j < size; j++){
            if(c[j] == current_char){
                cout << (void*)&c[j] << " ";
            }
        }
        cout << endl;
        seen[i] = current_char;
    }
    if(seen[0] != c[0]){
        cout << "null";
    }
    cout << endl;
}

int main(){
    string input;
    cout << "Enter characters: ";
    getline(cin, input);

    showNoOfAppearances(&input[0], input.length());
    
    showIndices(&input[0], input.length());

    showAddress(&input[0], input.length());
    
    return 0;
}