#include <iostream>

using namespace std;


//implemented using array
class Queue{
    private: 
        int *p_queue;
        int length;
        int head;
        int tail;

        void refreshCircularIdx(){
            head = head % length;
            tail = tail % length;
        }

        void extendArray(){
            int prevLength = length;
            length = length * 2;
            int *temp = (int*)malloc(length * sizeof(int));
            for(int i = 0 ; i < prevLength; i++){
                *(temp + i) = *(p_queue + i);
            }
            p_queue = temp;
        }
    
    public:

        Queue(int l){
            length = l;
            int *temp = (int*)malloc(l * sizeof(int));
            p_queue = temp;
            head = 0;
            tail = 0;
        }

        void enQueue(int num){
            if(isFull()){
                extendArray();
            }
           
            *(p_queue + (tail % length)) = num;
            
            tail++;
            
        }

        int deQueue(){
            if(isEmpty()){
                return -1;
            }
            int queued = *(p_queue + (head % length));
            head++;
            return queued;

        }

        int peek(){
            if(isEmpty()){
                return -1;
            }
            return *(p_queue + head);
        }

        bool isEmpty(){
            if((head - tail) == 0){
                return true;
            }
            return false;
        }

        bool isFull(){
            if(getLength() == length){
                return true;
            }
            return false;
        }

        int getLength(){
            return tail - head;
        }

       
};

int main(){
    Queue queue(5);
    
    
    return 0;
}