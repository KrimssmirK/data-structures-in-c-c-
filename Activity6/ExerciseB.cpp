#include <iostream>

using namespace std;

struct Node{
    int value;
    struct Tree *left;
    struct Tree *right;
};

int main(){
    Node root;
    root.value = 2;
    
    Node node1;
    node1.value = 7;

    Node node2;
    node2.value = 5;

    Node node3;
    node3.value = 2;

    Node node4;
    node4.value = 6;

    Node node5;
    node5.value = 9;

    Node node6;
    node6.value = 5;

    Node node7;
    node7.value = 11;

    Node node8;
    node8.value = 4;

    return 0;
}