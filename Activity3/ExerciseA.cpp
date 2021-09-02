#include <iostream>

using namespace std;


//implemented using array
class Stack{
    private:
        //private attributes
        int *p_stack;
        int length;
        int idx;

        //methods
        void extendArray(){
            int prevLength = length;
            length = length * 2;
            int *temp = (int*)malloc(length * sizeof(int));
            for(int i = 0; i < prevLength; i++){
                *(temp + i) = *(p_stack + i);
            }
            p_stack = temp;
        }
    public:
        //constructor
        Stack(int l){
            length = l;
            int *temp = (int*)malloc(length * sizeof(int)); // allocating array in the memory
            p_stack = temp;
            idx = -1;
        }
        
        //methods
        void push(int num){
            idx++;
            if(isFull()){
                extendArray();
            }
            
            *(p_stack + idx) = num;
            
        }

        int pop(){
            if(isEmpty()){
                return -1;
            }
            int popped = *(p_stack + idx);
            idx--;
            return popped;
        }

        int top(){
            return *(p_stack + idx);
        }

        int getLength(){
            return length;
        }

        bool isEmpty(){
            if(idx == -1){
                return true;
            }
            return false;
        }

        bool isFull(){
            if(idx == length){
                return true;
            }
            return false;
        }
};

int main(){
    Stack stack(10);
    
    int entered = 0;
    int count = 0;

    while(entered != 999){
        cout << "Enter a number: ";
        cin >> entered;
        if(entered != 999){
            stack.push(entered);
            count++;
        }
    }
    
    int enteredNums[count];

    //storing the elements in order to the new array which is enteredNums
    for(int i = count - 1; i >= 0; i--){
        enteredNums[i] = stack.pop();
    }

    cout << "Numbers in STACK: ";

    int total = 0;

    for(int i = 0; i < count; i++){
        cout << enteredNums[i] << " ";
        total += enteredNums[i];
    }
    
    cout << endl;
    cout << "AVERAGE: " << total / count << endl;

    return -1;
}