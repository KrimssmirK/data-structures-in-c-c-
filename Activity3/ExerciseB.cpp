#include <iostream>

using namespace std;


//implemented using array
class Queue{
    private: 
        int *p_queue;
        int length;
        int head;
        int tail;

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

        int search(int search_num){
            int currentNum;
            for(int i = 0; i < getLength(); i++){
                currentNum = *(p_queue + ((head + i) % length));
                if(currentNum == search_num){
                    return i + 1;
                }
            }
            return -1;
        }
       
       int getNum(int position){
           int idx = position;
           return *(p_queue + ((head + idx) % length));
       }
};

void showNewContentAndAverage(Queue queue, int position){
    int currentNum;
    int total = 0;
    int count = 0;
    cout << "New Queue Content: ";
    for(int i = 0 ; i < queue.getLength() ; i++){
        currentNum = queue.getNum(i);
        
        if(currentNum == queue.getNum(position - 1)){
            continue;
        }
        cout << currentNum << " ";
        total += currentNum;
        count++;
    }
    cout << endl;

    cout << "AVERAGE: " << double(total) / count << endl;
}

int main(){
    Queue queue(5);
    
    int num = 0;

    while(true){
        cout << "Enter a number: ";
        cin >> num;
        if(num == 999){
            break;
        }
        queue.enQueue(num);
    }

    int search_num;
    cout << "Enter a number to be searched: ";
    cin >> search_num;

    int position = queue.search(search_num);
    cout << "The position of " << search_num << " is " << position << "." << endl;

    showNewContentAndAverage(queue, position);
    
    return 0;
}