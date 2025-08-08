#include<iostream>
using namespace std;

class Node{
    public:
        Node* previous;
        Node* next;
        int key;
        int data;

        //constructor
        Node(){
            key = 0;
            data = 0;
            previous = NULL;
            next = NULL;
        }

        //parameterized constructor 
        Node(int k, int d){
            key = k;
            data = d;
        }
};

class doublyLinkedList{
    public:
        Node* head;

        //constructor
        doublyLinkedList(){
            head = NULL;
        }

        //parameterized constructor
        doublyLinkedList(Node* n){
            head = n;
        }

        //methods
        //1. check if node exists using key value
        Node* nodeExists(int k){
            Node* temp = NULL;
            Node* ptr = head;

            while (ptr != NULL)
            {
                if(ptr->key == k){
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp; 
        }

        //2. append node at the end of the DLL
        void appendNode(Node* n){
            if (nodeExists(n->key) != NULL)
            { 
                cout<<"Node already exists."<< n->key << "Append node with a different key."<<endl;
            }else{
                if (head == NULL){
                    head = n;
                    cout<<"Node appended. "<<endl;
                }else{
                    Node* ptr = head;
                    while (ptr->next != NULL)
                    {
                       ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->previous = ptr;
                    cout<<"Node appended. "<<endl;
                }
            }
        }

        //3. prepend new node at the front
        void prependNode(Node* n){
            if (nodeExists(n->key) != NULL)
            { 
                cout<<"Node already exists."<< n->key << "Prepend node with a different key."<<endl;
            }else{
                if (head == NULL)
                {
                   head = n;
                   cout<<"Node prepended. "<<endl;
                }
                else
                {
                    head->previous = n;
                    n->next = head;
                    head = n;
                    
                    cout<<"Node prepended. "<<endl;
                } 
            }
        }

        //4. insert node after node with inputted key
        void insertNodeAfter(int k, Node* n){
            Node* ptr = nodeExists(k);
            if (ptr == NULL)
            {
                cout<<"No node with key value = "<<k<<"exists."<<endl;
            }
            else
            {   //check if the key of the new node exists
                if (nodeExists(n->key) != NULL){
                    cout<<"Node already exists."<< n->key << "Insert node with a different key."<<endl;
                }else{
                    //if this key does not exist then, execute the following code
                    Node* nextNode = ptr->next;

                    if (nextNode == NULL) //inserting at the end
                    {   
                        ptr->next = n;
                        n->previous = ptr;
                        cout << "Node Inserted at the END" << endl;
                    }else{   //inserting in between
                        n->next = nextNode;
                        nextNode->previous = n;
                        n->previous = ptr;
                        ptr->next = n;
                        
                        cout << "Node inserted after key = " <<k<< endl;
                    }
                }
            }  
        }

        //5. delete node
        void deleteNodeByKey(int k){
            Node* ptr = nodeExists(k);
            if (ptr == NULL){
                cout<<"No node with key value = "<<k<<"exists."<<endl;
            }
            else{ 
                if(head==NULL){
                    cout<<"DLL is empty"<<endl;
                }else if(head != NULL){
                    if (head->key == k){ //in case you wanna delete the head node
                        head = head->next;
                        cout<<"Unlinked the node with key value = "<<k<<endl;
                    }else{
                        Node* nextNode = ptr->next;
                        Node* prevNode = ptr->previous;

                        if (nextNode == NULL){  //deleting at the end
                            prevNode->next = NULL;
                            cout<<"Unlinked the node with key value = "<<k<<endl;
                        }else{  //deleting in between
                            prevNode->next = nextNode;
                            nextNode->previous = prevNode;
                            cout<<"Unlinked the node with key value = "<<k<<endl;
                        }
                    }
                }
            }
        }

        //6. update node by inputting key and new data
        void updateNode(int k, int d){
            Node* ptr = nodeExists(k);
            if (ptr == NULL){  //means if node with key k does not exist
                cout<<"No node with key value = "<<k<<"exists."<<endl;
            }else{ //means if such node exists then
                ptr->data = d;
                cout<<"Node with key value = "<<k<<"now holds data value = "<<d<<endl;
            }   
        }

        //7. print the doubly linked list
        void printList(){
            if (head == NULL){
                cout<<"Cannot print. DLL is empty."<<endl;
            }else{
                cout<<"DLL is as follows:"<<endl;
                Node* temp = head;
                while (temp!=NULL)
                {
                    cout<<" "<<temp->key<<" : "<< temp->data<<" "<<"<--->";
                    temp = temp->next;
                } 
            }
        }
};

int main(){

    doublyLinkedList obj;
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

        switch (option)
        {
        case 0:
            break;
       
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

            obj.updateNode(key1, data1);

            break;

        case 6:
            obj.printList();

            break;

        case 7:
            system("cls");
            break;        
        
        default:
            cout << "Enter Proper Option number " << endl;
            break;
        }
    } while (option!=0);
    
    return 0;
}