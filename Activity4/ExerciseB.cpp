#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
    Node *prev;
};

class DoublyLinkedList{
    private:
        Node *head;
        Node *tail;

    public:
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }
        void insert(int value){
            Node *temp = (Node*)malloc(sizeof(Node));
            temp->value = value;
            temp->next = NULL;
            temp->prev = NULL;
            Node *currentNode = head;
            if(isEmpty()){
                head = temp;
                tail = temp;
                return;
            }else{
                while(currentNode->next != 0){
                    currentNode = currentNode->next;
                }
                currentNode->next = temp;
                temp->prev = currentNode;
                tail = temp;
            }
        }

        bool isEmpty(){
            if(head == 0){
                return true;
            }
            return false;
        }

        void remove(){
            Node *temp = head->next;
            head->next = NULL;
            temp->prev = NULL;
            free(head);
            head = temp;
        }

        void remove_last(){
            Node *second_from_last = tail->prev;
            tail->next = NULL;
            tail->prev = NULL;
            second_from_last->next = NULL;
            free(tail);
            tail = second_from_last;
        }

        Node* getHead(){
            return head;
        }

        Node* getTail(){
            return tail;
        }
};
class Stack{
    private:
        DoublyLinkedList list;
    public:
        void push(int value){
            list.insert(value);
        }

        void pop(){
            list.remove_last();
        }

        int peek(){
            return (list.getTail())->value;
        }

        void printContent(){
            Node *currentNode = list.getTail();
            while(currentNode != 0){
                cout << currentNode->value << " ";
                currentNode = currentNode->prev;
            }
            cout << endl;
        }
};

class Queue{
    private:
        DoublyLinkedList list;
    public:
        void push(int value){
            list.insert(value);
        }
        
        void pop(){
            list.remove();
        }

        int peek(){
            return (list.getHead())->value;
        }

        void printContent(){
            Node *currentNode = list.getHead();
            while(currentNode != 0){
                cout << currentNode->value << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
};
int main(){
    //simulating stack
    Stack stack;
    stack.push(3);
    stack.push(2);
    stack.printContent();
    stack.pop();
    stack.push(5);
    stack.pop();
    cout << stack.peek() << endl;

    //simulating queue
    Queue queue;
    queue.push(3);
    queue.push(2);
    queue.printContent();
    queue.pop();
    queue.push(5);
    queue.pop();
    cout << queue.peek() << endl;
    return 0;
}