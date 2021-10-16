#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
};

class SinglyLinkedList{
    private:
        Node *head;

    public:

        SinglyLinkedList(){
            head = NULL;
        }
        void insert_to_end(int value){
            Node *temp = (Node*)malloc(sizeof(Node));
            temp->value = value;
            temp->next = NULL;
            Node *current = head;
            if(isEmpty()){
                head = temp;
                return;
            }else{
                while(current->next != 0){
                    current = current->next;
                }
                current->next = temp;
            }
        }

        void insert_to_front(int value){
            Node *temp = (Node*)malloc(sizeof(Node));
            temp->value = value;
            temp->next = head;
            head = temp;
        }

        void insertAt(int pos, int value){
            pos -= 1;
            int count = 1;
            Node *temp = (Node*)malloc(sizeof(Node));
            temp->value = value;
            Node *currentNode = head;
            while(currentNode->next != 0){
                if(count == pos){
                    temp->next = currentNode->next;
                    currentNode->next = temp;
                    return;
                }
                currentNode = currentNode->next;
                count++;
            }
        }

        bool isEmpty(){
            if(head == 0){
                return true;
            }
            return false;
        }

        Node* getHead(){
            return head;
        }

        bool has_cycle() {
            Node* skip1 = head;
            Node* skip2 = head;
            while(skip1->next != NULL && skip2->next->next != NULL){
                skip1 = skip1->next;
                skip2 = skip2->next->next;
                if(skip1 == skip2){
                    return true;
                }
            }
            return false;
        }
};



int main(){
    SinglyLinkedList list;
    
    int input;

    while(true){
        cin >> input;
        if(input == 999){
            list.insertAt(3,input);
            break;
        }
        if(input >= 10){
            list.insert_to_end(input);
        }else{
            list.insert_to_front(input);
        }
    }

    cout << "cycle: " << list.has_cycle() << endl; //test


    cout << "Linked List contains: ";

    Node *current = list.getHead();
    while(current != 0){
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
    
    return 0;
}