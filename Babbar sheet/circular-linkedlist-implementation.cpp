#include <iostream>
using namespace std;

class Node{
    public:
//data members
        int key;
        int data;
        Node* next;
//constructor
        Node(){
            key = 0;
            data = 0;
            next = NULL;
        }
//parameterized constructor
        Node(int k, int d){
            key = k;
            data = d;
        }
};

class circularLinkedList{
    public:

//data members
        Node* head;

//default constructor
        circularLinkedList(){
            head = NULL;
        }

//method functions 
//1. check if node with key value k exists 
        Node* nodeExists(int k){
            Node* temp = NULL;
            Node* ptr = head;

            if (ptr==NULL){  //means linked list is empty and has no nodes
                return temp;
            }
            else{
                do{
                    if (ptr->key == k){
                        temp = ptr;
                    }
                    ptr = ptr->next;
                } while (ptr!=head);
                
                return temp;
            }
        }

//2. append node at the end of the CLL
        void appendNode(Node* new_node){
            if (nodeExists(new_node->key) != NULL){ //if key is not unique
             cout<<"Node with key: "<<new_node->key<<" already exists"<<endl;
            }
            else{ //if key is unique
                //if it is a head node
                if (head==NULL){
                   head = new_node;
                   new_node->next = head;
                   cout<<"Made the node as head node."<<endl;
                }else{
                    Node* ptr = head;
                    while (ptr->next!=head)
                    {
                       ptr = ptr->next;
                    }
                    ptr->next = new_node;
                    new_node->next = head;

                    cout<<"Node with key: "<<new_node->key<<" appended."<<endl;
                    
                }
            }
        }

//3. prepend new node to the start of CLL
        void prependNode(Node* new_node){
            if (nodeExists(new_node->key) != NULL){
                cout<<"Node with key: "<<new_node->key<<" already exists"<<endl;
            }else{
                if (head==NULL){
                   head = new_node;
                   new_node->next = head;
                   cout<<"Made the node as head node."<<endl;
                }else{
                    Node* ptr = head;
                    while (ptr->next != head){
                        ptr = ptr->next;
                    }
                    ptr->next = new_node;
                    new_node->next = head;
                    head = new_node;

                    cout<<"Node with key: "<<new_node->key<<" prepended."<<endl;  
                } 
            }
        }

// 4. Insert a Node after a particular node in the list
        void insertNodeAfter(int k, Node* new_node){

            Node* ptr = nodeExists(k);

            if (ptr == NULL){
                cout<<"Node with key: "<<k<<" does not exist."<<endl;  
            }else{
                //if this node exists then
                //insert new node after it

                //case1: you want to insert new node at the end of the list
                if (ptr->next == head){
                    new_node->next = head;
                    ptr->next = new_node;
                    cout << "Node Inserted at the End" << endl;
                }else{  //case2: you want to insert new node somewhere in between
                   new_node->next = ptr->next;
                   ptr->next = new_node;
                   cout << "Node Inserted in between after key:"<<k<< endl;
                }
            }
        }

// 5. Delete node by unique key
        void deleteNodeByKey(int k){
            //check if node with key k exists or not
            Node* ptr = nodeExists(k);
            if (ptr==NULL){
                cout << "No node exists with key value OF : " << k <<endl;
            }else{//in case the node exists, then delete it
               if (ptr == head){ //case1: you want to delete the head node
                    if (head->next == NULL){ //means if the CLL has only 1 node ie the head node
                        head = NULL;
                        cout<<"Head node Unlinked... List Empty";
                    }else{ //means if the CLL has multiple nodes AND you want to delete the head node
                        Node* ptr1 = head;   //ptr1 is a local ptr that has scope only within this else block
                        while(ptr1->next != head){
                            ptr1 = ptr1->next;
                        } //thus we reach the last node and ptr1 is now the pointer of this last node
                        ptr1->next = head->next;  //make last node point to the the node that is after the head node
                        head = head->next; //thus after that we can change the head node also
                        cout << "Node UNLINKED with keys value : " << k << endl;
                    }
                }else{ //means you wanna delete a node that is not a head node
                    Node* temp = NULL;
                    Node* prevptr = head;  //initially the 1st node
                    Node* currentptr = head->next;  //initially the 2nd node
                     
                    while (currentptr != NULL){
                        if (currentptr->key == k){  //if you wanna delete the 2nd node
                            temp = currentptr;
                            currentptr = NULL;                            
                        }else{ //keep moving till you find the node that you wanna delete
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                    }//thus now the key of the node that currentptr was pointing to is found and we have temp = currentptr;
                        
                    prevptr->next = temp->next;  //this line makes sure that node is dropped and instead it links the nodes before and after it
                    cout << "Node UNLINKED with keys value : " << k << endl;
                }
            }
        }
            
// 6. Update data field of a node using its key
        void updateNodeByKey(int k, int d){
            Node* ptr = nodeExists(k);
            if (ptr != NULL){
              ptr->data = d;
              cout<<"Node with key: "<<k<<" now contains data: "<<d<<endl;
            }else{
                cout<<"Node with key: "<<k<<" does not exist."<<endl;
            }  
        }

//7. print the CLL
    void printList(){
        Node* ptr = head;

        if (head == NULL){
            cout<<"Doubly Linked List is empty. Cannot be printed."<<endl;
        }else{

            cout << endl << "Head address : " << head << endl;
            cout << "Circular Linked List Nodes : " << endl;

            Node* temp = head;
            
            do{
                cout<<temp->key<<" : "<<temp->data<<" @ "<<temp->next<<" ---> ";
                temp = temp->next;
            } while (temp != head);
        } 
    }

};

int main(){

    circularLinkedList obj;
    int option;
    int key1, k1, data1;

    do{
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;

        Node* n1 = new Node();

        switch (option){
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;

            n1->key = key1;
            n1->data = data1;

            obj.appendNode(n1);

            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;

            n1->key = key1;
            n1->data = data1;

            obj.prependNode(n1);
            
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;

            n1->key = key1;
            n1->data = data1;

            obj.insertNodeAfter(k1, n1);

            break;

        case 4:
            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            
            obj.deleteNodeByKey(k1);
            
            break;

        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;

            obj.updateNodeByKey(key1, data1);

            break;

         case 6:
            obj.printList();
            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);
    

    return 0;
}