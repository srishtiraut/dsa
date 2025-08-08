#include<iostream>
using namespace std;

//node class
class Node{
    public:
        int key;
        int data;
        Node* next; //pointer variable of type node. Points to objects of data type 'Node'

        //make default constructor
        Node(){
            key=0;
            data=0;
            next=NULL;
        }

        //make parameterized constructor because what if you wanna create a waffle with custom toppings
        Node(int k, int d){
            key=k;
            data=d;
        }
};

//singly linked list class
class SinglyLinkedList{
    public:
        Node* head; //head is a pointer variable that points to the headnode/0th node. // just because head points to sth whose datatype is a node, head's own datatype is Node
       
       //default constructor
        SinglyLinkedList(){
            head = NULL;
        }

        //make parameterized constructor because what if you wanna create a waffle with custom toppings
        SinglyLinkedList(Node* n){ //pass by address; n is a pointer variable. n stores the address of a node
            head = n;
        }
// 1. check if the node exists by inputting its key value
        Node* nodeExists(int k){  //returns a pointer that can be used in other functions
            Node* temp = NULL;
            Node* ptr = head;

            while (ptr != NULL)
            {
                if(ptr->key == k){  //check if k = the key of the node that ptr is pointing towards
                    temp = ptr;
                }
                ptr = ptr->next; //so that now ptr points to agla node
                /*
                say at given time, ptr points to node P which looks like [key_P | data_P | next_P]
                'next_P' points to node named Q [key_Q | data_Q | next_Q]
                It is like saying arr++ :)))
                */
            }
            return temp;
       
        }

// 2. Append a node to the singly linked list at the end
        void appendNode(Node* n){
            //check if whatever node that we are appending has a key that already exists
            if (nodeExists(n->key) != NULL)
            {
                cout<<"Node already exists."<< n->key << "Append node with a different key."<<endl;
            }else{
                //check if at all SLL has 0 nodes or more
                if (head == NULL)
                {
                    head = n;
                    cout<<"Node appended. "<<endl;
                }else{
                    //traverse till end of nodes
                    Node* ptr = head;
                    while (ptr->next != NULL)
                    {
                        ptr = ptr->next;  
                    }
                    //in the end ptr becomes NULL on reaching the last node of the SLL
                    ptr->next = n; //accessing next pointer of the last node and giving it the value of new node n
                    cout<<"Node appended. "<<endl;
                } 
            }  
        }

// 3. Prepend node - attach node to the front of the SLL
        void prependNode(Node* n){
            if (nodeExists(n->key) != NULL)
            {   //again check if whatever node that we are prepending has a key that already exists
                cout<<"Node with this key already exists: "<< n->key << " Prepend node with a different key."<<endl;
            }else{
                n->next = head; //make the next of new node hold the value of head
                head = n;  //make head hold the value of n 
                //now n is the head node aka the first node of the SLL
                cout<<"Node prepended. "<<endl;
            }
        }

// 4. Insert new node somewhere after some node in the SLL
        void insertNodeAfter(int k, Node* n){
            Node* ptr = nodeExists(k);
            if (ptr == NULL)
            {
                cout<<"No node exists with key = "<<k<<endl;
            }else{
                if (nodeExists(n->key) != NULL){
                    cout<<"Node with this key already exists: "<< n->key <<endl;
                }else{
                    n->next = ptr->next;
                    ptr->next = n;
                    cout<<"Node inserted."<<endl;
                }
            }
        }

// 5. Delete a node having unique key=k
        void deleteNodeByKey(int k){
            if(head == NULL){  //means SLL has 0 nodes
                cout<<"Singly Linked List is empty. Cannot delete any node. "<<endl;
            }else if(head != NULL){
                if(head->key == k){  //if you want to delete the first node
                    head = head->next; //then make head point to the next node
                    cout<<"Node with key "<<k<< " has been unlinked."<<endl;
                }else{
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head->next;

                    while (currentptr != NULL)  //while you dont reach the end of the SLL
                    {
                       //means keep moving forward until you dont find the match
                       if (currentptr->key==k)
                       {
                        temp = currentptr;
                        currentptr = NULL;
                       }else{
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                       }
                    }

                       //once you find the requested node
                       if (temp!=NULL)
                       {
                        //start unlinking
                        prevptr->next = temp->next; //means make prevptr of next point to temp of next
                        cout<<"Node with key value = "<<k<<"has been unlinked."<<endl;
                       }else{
                        //if no node is found then
                         cout<<"No node with key value = "<<k<<" exists."<<endl;
                       }
                }
            }
        }

// 6. Update node by inputting key value and data        
        void updateNodeByKey(int k, int d){
            Node* ptr = nodeExists(k);  //if node with key=k exists then ptr points to that node
            if (ptr!=NULL)
            {
                //once the node is found, update that node's data field
                ptr->data = d;
                cout<<"Node having key = "<<k<<" has been updated successfully."<<endl;
            }else{
                //if no node is found then
                cout<<"No node with key value = "<<k<<" exists."<<endl;
            } 
        }
// 7. Print the singly linked list
        void printLinkedList(){
            Node* temp = head;
            if (head==NULL) //if there is no linking
            {
                cout<<"Empty linked list."<<endl;
            }
            else
            {   //if there are nodes linked together, print the key-data values node-by-node
                cout<<"Your singly linked list is as follows: "<<endl;
                
                while (temp!=NULL) //loop runs till end of SLL
                {
                    cout<<"["<<temp->key<<" : "<<temp->data<<"]"<<" ---> ";
                    temp = temp->next;
                }
            }
        }

};



int main(){

    //create objects
    SinglyLinkedList s;
    
    int option, key1, k1, data1;

    do
    {
        cout << "\n \nWhat operation do you want to perform on your Singly Linked List - SLL? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNode()" << endl;
        cout << "6. printLinkedList()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin>> option;
        Node* n1 = new Node(); //new Node() means one global object of datatype Node is created dynamically in the heap memory
        //Node* n1 means n1 is a pointer to that object
        
        switch (option)
        {
        case 0:
            break;
        
        case 1:
            cout<<"**Append Node Operation** \n Enter the key and data you wanna append to the SLL: "<<endl;
            cin>>key1;
            cin>>data1;

            n1->key = key1;  //key of the object that n1 points to is now = key1 
            n1->data = data1; //similarly for data field
            s.appendNode(n1);  //n1 and not &n1 is passed as argument because n1 is already a pointer variable and it was created dynamically in the memory
            /*
            If we had created n1 as 
                Node n1;
            then the correct way to call the appendNode method would have been
                s.appendNode(&n1);
            */
           break;

           case 2:
            cout<<"**Prepend Node Operation** \nEnter the key and data you wanna prepend to the SLL: "<<endl;
            cin>>key1;
            cin>>data1;

            n1->key = key1;  //key of the object that n1 points to is now = key1 
            n1->data = data1; //similarly for data field
            s.prependNode(n1);  //n1 and not &n1 is passed because n1 is already a pointer variable and it was created dynamically in the memory
    
            break;

            case 3:
            cout<<"**Insert Node After Operation** \nEnter the key after which you wanna insert new node to the SLL: "<<endl;
            cin>>k1;
            
            cout<<"Enter the key and data values for the new node:  "<<endl;
            cin>>key1;
            cin>>data1;

            n1->key = key1;
            n1->data = data1;
            s.insertNodeAfter(k1, n1);

            break;

            case 4:
            cout<<"**Delete Node By Key Operation** \nEnter the key of the node that you wish to delete: "<<endl;
            cin>>k1;

            s.deleteNodeByKey(k1);

            break;

            case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;

            s.updateNodeByKey(key1, data1);

            break;

            case 6:
            s.printLinkedList();
            break;

            case 7:
            system("cls");
            break;
    
            default:
            cout << "Enter Proper Option number " << endl;

        }
    } while (option!=0);
    

    return 0;
}
