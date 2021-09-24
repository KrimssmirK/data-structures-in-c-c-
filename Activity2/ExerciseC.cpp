#include <iostream>
#include <string>

using namespace std;

const int NO_MEMBERS = 3;
const int SIZE = 30;

//addresses coded
const char kenji_address[SIZE] = "honmachi";
const char romeo_address[SIZE] = "";
const char mark_address[SIZE] = "";

const char kenji_id = "2019-200012";
const char romeo_id = "";
const char mark_id = "";

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
    return true;
}

string getAddress(char *student_no){
    if(isSame(student_no, kenji_id)){
        return kenji_address;
    }else if(isSame(student_no, romeo_id)){
        return romeo_address;
    }else if(isSame(student_no, mark_id)){
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