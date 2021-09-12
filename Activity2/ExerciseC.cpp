#include <iostream>
#include <string>

using namespace std;

const int NO_MEMBERS = 3;
const int SIZE = 30;

//addresses coded
const char address1[SIZE] = "honmachi";
const char address2[SIZE] = "";
const char address3[SIZE] = "";

struct Group{
    char student_no[SIZE];
    char program[SIZE];
    char number[SIZE];
    char city_address[SIZE];
};

void createGroup(Group *ptr){
    for(int i = 0 ; i < NO_MEMBERS ; i++){
        cout << "Student" << i + 1 << endl;
        cout << "student no: ";
        cin >> ptr[i].student_no;
        cout << "program: ";
        cin >> ptr[i].program;
        cout << "number: ";
        cin >> ptr[i].number;
        cout << endl;
    }
}

bool isSame(char *c1, const char *c2){
    while(*c1 != '\0' && *c2 != '\0'){
        if(*c1 != *c2){
            return false;
        }
        c1++;
        c2++;
    }
    return true;
}

string getAddress(char *student_no){
    if(isSame(student_no, "2019-200012")){
        return address1;
    }else if(isSame(student_no, "2019-XXXXXX")){
        return address2;
    }else if(isSame(student_no, "2019-XXXXXX")){
        return address3;
    }else{
        return "none";
    }
}

void displayMemberInfo(Group *ptr){
    cout << "Group1[MEMBERS]" << endl;
    for(int i = 0 ; i < NO_MEMBERS ; i++){
        cout << "Student" << i + 1 << endl;
        cout << "student no: " << ptr[i].student_no << endl;
        cout << "program: " << ptr[i].program << endl;
        cout << "number: " << ptr[i].number << endl;
        cout << "address: " << getAddress(ptr[i].student_no) << endl << endl;
    }
}

int main(){
    Group *ptr, group1[NO_MEMBERS];
    ptr = group1;
    
    createGroup(ptr);

    displayMemberInfo(ptr);

    return 0;
}