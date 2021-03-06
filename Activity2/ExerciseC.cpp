#include <iostream>
#include <string>

using namespace std;

const int NO_MEMBERS = 3;
const int SIZE = 30;

//addresses coded
const char kenji_address[SIZE] = "Caloocan City";
const char romeo_address[SIZE] = "Quezon City";
const char mark_address[SIZE] = "Nueva Ecija";



struct Group{
    char student_no[SIZE];
    char program[SIZE];
    char number[SIZE];
    char city_address[SIZE];
};

void createGroup(Group *ptr){
    for(int i = 0 ; i < NO_MEMBERS ; i++){
        cout << "[Student" << i + 1 << "]" << endl;
        cout << "student no: ";
        cin >> ptr[i].student_no;
        cout << "program: ";
        cin >> ptr[i].program;
        cout << "number: ";
        cin >> ptr[i].number;
    }
    cout << endl;
}

bool isSame(char *c1, const char *c2){
    while(*c1 != '\0' && *c2 != '\0'){
        if(*c1 != *c2){
            return false;
        }
        c1++;
        c2++;
    }
    if(*c1 != '\0' || *c2 != '\0'){
        return false;
    }
    return true;
}

string getAddress(char *student_no){
    if(isSame(student_no, "2019-200012")){
        return kenji_address;
    }else if(isSame(student_no, "2019-200124")){
        return romeo_address;
    }else if(isSame(student_no, "2019-200122")){
        return mark_address;
    }else{
        return "none";
    }
}

void displayMemberInfo(Group *ptr){
    cout << "Group1[MEMBERS]" << endl;
    for(int i = 0 ; i < NO_MEMBERS ; i++){
        cout << "[Student" << i + 1 << "]" << endl;
        cout << "student no: " << ptr[i].student_no << endl;
        cout << "program: " << ptr[i].program << endl;
        cout << "number: " << ptr[i].number << endl;
        cout << "address: " << getAddress(ptr[i].student_no) << endl;
    }
}

int main(){
    Group *ptr, group1[NO_MEMBERS];
    //Group *ptr;
    //Group group1[NO_MEMBERS];

    ptr = group1;
    

    createGroup(ptr);

    displayMemberInfo(ptr);

    return 0;
}