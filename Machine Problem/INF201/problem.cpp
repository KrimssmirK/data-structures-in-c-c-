#include <iostream>
#include <stack>
#include <string>

using namespace std;



int main() {
    stack<int> stack_enqueue, stack_dequeue;
    int answer[10];
    int index = 0;
 
    int no_of_queries;
    cin >> no_of_queries;
    
    while(no_of_queries--){
        int number;
        cin >> number;
        if(number == 1){
            int data;
            cin >> data;
            stack_enqueue.push(data);
        }else if(number == 2){
            while(!stack_enqueue.empty()){
                int popped = stack_enqueue.top();
                stack_dequeue.push(popped);
                stack_enqueue.pop();
            }
            stack_dequeue.pop();
            while(!stack_dequeue.empty()){
                int popped = stack_dequeue.top();
                stack_enqueue.push(popped);
                stack_dequeue.pop();
            }
        }else if(number == 3){
            while(!stack_enqueue.empty()){
                int popped = stack_enqueue.top();
                stack_dequeue.push(popped);
                stack_enqueue.pop();
            }
            answer[index++] = stack_dequeue.top();
            while(!stack_dequeue.empty()){
                int popped = stack_dequeue.top();
                stack_enqueue.push(popped);
                stack_dequeue.pop();
            }
        }
    }

    while(--index >= 0){
        cout << answer[index] << endl;
    }
 
    return 0;
}

