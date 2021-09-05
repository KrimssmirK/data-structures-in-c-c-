#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isVowel(char c){
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < sizeof(vowels)/sizeof(char); i++){
        if(vowels[i] == c){
            return true;
        }
    }
    return false;
}

bool isConsonant(char c){
    char consonants[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    for(int i = 0; i < sizeof(consonants)/sizeof(char); i++){
        if(consonants[i] == c){
            return true;
        }
    }
    return false;
}

void getNoOfConsonantsAndVowelsAndSpaces(string input, int *vowels, int *consonants, int *spaces){
    for(int i = 0 ; i < input.length(); i++){
        char current_character = tolower(input[i]);
        if(isVowel(current_character)){
            (*vowels)++;
        }else if(current_character == ' '){
            (*spaces)++;
        }else if(isConsonant(current_character)){
            (*consonants)++;
        }
    }
}

int main(){
    string input;
    int no_of_consonants;
    int no_of_vowels;
    int no_of_spaces;

    cout << "Enter characters: ";
    getline(cin, input);

    getNoOfConsonantsAndVowelsAndSpaces(input, &no_of_vowels, &no_of_consonants, &no_of_spaces);

    cout << "consonants: "<< no_of_consonants << endl;
    cout << "vowels: "<< no_of_vowels << endl;
    cout << "spaces: "<< no_of_spaces << endl;
    
    return 0;
}