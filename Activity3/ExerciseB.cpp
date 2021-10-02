#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 5;
//implemented using array
class Queue{
    private: 
        int *p_queue;
        int length;
        int head;
        int tail;

        void reset_head_tail(){
            head = -1;
            tail = -1;
        }

    public:

        Queue(int l){
            length = l;
            p_queue = (int*)malloc(l * sizeof(int));
            head = -1;
            tail = -1;
        }

        void enQueue(int num){
            if(isFull()){
                length *= 2;
                p_queue = (int*)realloc(p_queue, length*sizeof(int));
            }
            if(isEmpty()){
                head++;
            }
            tail++;
            *(p_queue + (tail % length)) = num;
        }

        int deQueue(){
            if(isEmpty()){
                return -1;
            }
            int deQueued = *(p_queue + (head % length));
            head++;
            if(head > tail){
                reset_head_tail();
            }
            return deQueued;
        }

        int peek(){
            if(isEmpty()){
                return -1;
            }
            return *(p_queue + (head % length));
        }

        bool isEmpty(){
            if(head == -1){
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
            return (tail - head) + 1;
        }

        int getPosition(int search_num){
            for(int i = 0; i < getLength(); i++){
                if(*(p_queue+((head+i)%length)) == search_num){
                    return i + 1;
                }
            }
            return -1;
        }
};

int main(){
    Queue queue(SIZE);
    
    int num;

    while(true){
        cout << "Enter a number: ";
        cin >> num;
        if(num == 999){
            break;
        }
        queue.enQueue(num);
    }

    int searched;
    cout << "Enter a number to be searched: ";
    cin >> searched;

    int pos = queue.getPosition(searched);
    
    cout << "The position of " << searched << " is " << pos << "." << endl;

    Queue newQueue(queue.getLength());

    int count = 1;
    while(!queue.isEmpty()){
        if(count == pos){
            queue.deQueue();
        }
        if(!queue.isEmpty()){
            newQueue.enQueue(queue.deQueue());
        }
        // newQueue.enQueue(queue.deQueue());
        count++;
    }

    cout << "New Queue Content: ";
    int total = 0;
    while(!newQueue.isEmpty()){
        int dequeued = newQueue.deQueue();
        cout << dequeued << " ";
        total += dequeued;
    }
    cout << endl;

    cout << "AVERAGE: " << (double)total / (count - 1) << endl;
    return 0;
}