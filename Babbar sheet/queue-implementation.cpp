#include <iostream>
using namespace std;

class Queue{

    private:
        int arr[5];
        int rear;
        int front;
    
    public:
        Queue(){  //create a constructor. it will be called every time a new object is created.
            rear = -1;
            front = -1;
            //make everything to 0 initially
            for (int i=0; i<5; i++){
               arr[i] = 0;
            } 
        }

        //member functions aka methods
        bool isEmpty(){
            if (front == -1 && rear == -1){
                return true;
            }else{
                return false;
            }
            
        }

        bool isFull(){
            if (rear == sizeof(arr)-1){
                return true;
            }else{
                return false;
            }   
        }

        void enqueue(int value){
            if (isFull())
            {   
                cout<<"Queue is FULL!"<<endl;
                // return ;
            }else if(isEmpty()){
                rear = 0;
                front = 0;
                arr[rear] = value;
            }else{
                rear++; 
                arr[rear] = value;
            } 
        }

        int dequeue(){

            int temporary_holder_x = 0;

            if (isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return 0;
            }else if (front == rear){ //checking if the queue has only 1 item
               temporary_holder_x = arr[front];
               arr[front] = 0;  //because you also wanna delete the front item
               front = -1;
               rear = -1;
               return temporary_holder_x;
            }else{ //in case the queue has more than 1 items
                temporary_holder_x = arr[front];
                arr[front] = 0;  //because you also wanna delete the front item
                front++;
                return temporary_holder_x;
            }
        }

        int count(){
            // int total_number_of_items = rear-front+1;
            // return total_number_of_items;
            return (rear-front+1);
        }

        void display(){
            cout << "All values in the Queue are - " << endl;
            for (int i = 0; i < 5; i++)
            {
                cout<<arr[i]<<" ";
            }  
        }
};

int main(){


    Queue q1;
    int option, value;

    do
    {
        cout << "\n \nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. enqueue()" << endl;
        cout << "2. dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin>> option;
        switch (option)
        {
        case 0:
            break;
        
        case 1:
            cout<<"Enter the item you wanna insert into the queue: "<<endl;
            cin>>value;
            q1.enqueue(value);
           break;

        case 2:
            cout<<"Dequeue-ing the item at the front of the queue. "<<endl;
            cout<<"Dequeued item is: "<< q1.dequeue();
            break;

        case 3:
            if (q1.isEmpty())
            {
                cout<<"Queue is empty."<<endl;
            }else{
                cout<<"Queue is NOT empty."<<endl;
            }
            break;

        case 4:
            if (q1.isFull())
            {
                cout<<"Queue is full."<<endl;
            }else{
                cout<<"Queue is NOT full."<<endl;
            }
            break;

        case 5:
            cout<<"count() => Total number of items in the queue is: "<< q1.count()<<endl;
            break;

        case 6:
            cout << "display() fx called. " << endl;
            q1.display();
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