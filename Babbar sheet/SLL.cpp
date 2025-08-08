#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;    //declare a pointer to a Node

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){
//     Node* node1 = new  Node();
//     node1->data = 100;          //arrow operator  is used because node1 is a pointer variable and not a normal variable
//     cout<<"node1->data = "<< node1->data <<endl;
    
    
//     Node* node2 = new Node();
//     node2->data = 20;
//     node1->next = node2;
// cout<<"node2->data = "<< node2->data <<endl;
//     cout<<"node2->next = "<< node2->next <<endl; 
//     cout<<"node1->next = "<< node1->next <<endl; 
    
    
    Node* node3 = new Node(23);
    
    
    cout<<"node1->data = "<< node3 ->data <<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}