#include <iostream>
#include <string>
#include <cctype>

using namespace std;


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
        if(current_character == 'a' || current_character == 'e' || current_character == 'i' || current_character == 'o' || current_character == 'u'){
            (*vowels)++;
        }else if(current_character == ' '){
            (*spaces)++;
        }else if(isConsonant(current_character)){
            (*consonants)++;
        }
    }
}



// int getNoOfConsonants(string input){
//     int no_of_consonants = 0;
//     for(int i = 0; i < input.length(); i++){
//         char current_character = input[i];
//         if(current_character != ' ' && current_character != 'a' && current_character != 'e' && current_character != 'i' && current_character != 'o' && current_character != 'u'){
//             no_of_consonants++;
//         }
//     }
//     return no_of_consonants;
// }

// int getNoOfVowels(string input){
//     int no_of_vowels = 0;
//     for(int i = 0; i < input.length(); i++){
//         char current_character = input[i];
//         if(current_character != ' ' && current_character == 'a' || current_character == 'e' || current_character == 'i' || current_character == 'o' || current_character == 'u'){
//             no_of_vowels++;
//         }
//     }
//     return no_of_vowels;
// }

// int getNoOfSpaces(string input){
//     int no_of_spaces = 0;
//     for(int i = 0; i < input.length(); i++){
//         char current_character = input[i];
//         if(current_character == ' '){
//             no_of_spaces++;
//         }
//     }
//     return no_of_spaces;
// }

int main(){
    string input;
    int no_of_consonants;
    int no_of_vowels;
    int no_of_spaces;

    cout << "Enter characters: ";
    getline(cin, input);

    // no_of_consonants = getNoOfConsonants(input);
    // no_of_vowels = getNoOfVowels(input);
    // no_of_spaces = getNoOfSpaces(input);

    getNoOfConsonantsAndVowelsAndSpaces(input, &no_of_vowels, &no_of_consonants, &no_of_spaces);

    cout << "consonants: "<< no_of_consonants << endl;
    cout << "vowels: "<< no_of_vowels << endl;
    cout << "spaces: "<< no_of_spaces << endl;
    
    return 0;
}