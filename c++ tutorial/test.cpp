#include <iostream>
#include <string>

using namespace std;

struct Student{
    string name;
    int age;
};

int main(){
    //struct
    Student student1;
    student1.name = "kenji";
    student1.age = 22;

    cout << student1.name << endl;

    //array of structure
    Student students[5];
    students[0].name = "romeo";


}
