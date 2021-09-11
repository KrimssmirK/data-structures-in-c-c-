#include <iostream>

using namespace std;

//implemented using array
class Stack{
    private:
        //private attributes
        int *p_stack;
        int length;
        int idx;

    public:
        //constructor
        Stack(int l){
            length = l;
            p_stack = (int*)malloc(length * sizeof(int)); // allocating array in the memory
            idx = -1;
        }
        
        //methods
        void push(int num){
            idx++;
            if(isFull()){
                int doubledLength = 2*length*sizeof(int);
                p_stack = (int*)realloc(p_stack, doubledLength);
                length = doubledLength;
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

    while(true){
        cout << "Enter a number: ";
        cin >> entered;
        if(entered == 999){
            break;
        }
        stack.push(entered);
        count++;
    }
    
    Stack orderedStack(count);

    while(!stack.isEmpty()){
        orderedStack.push(stack.pop());
    }

    cout << "Numbers in STACK: ";

    int total = 0;

    while(!orderedStack.isEmpty()){
        int n = orderedStack.pop();
        cout << n << " ";
        total += n;
    }
    
    cout << endl;
    cout << "AVERAGE: " << (double)total / count << endl;

    return 0;
}