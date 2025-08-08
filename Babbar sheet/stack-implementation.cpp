 #include<iostream>
 #include <string>   //header files
 using namespace std;

class Stack{
    private:   //data members
        int top;
        int arr[5];

    public:   
        //create a default constructor
        Stack (){
            top = -1;
            for (int i=0; i<5; i++)
            {
                arr[i] = 0;
            }  
        }
    //member functions
    bool isEmpty(){
        if (top == -1){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if (top == 4)
            return true;
        else
            return false;

    }

    void push(int val){
        //always check if the stack has space for a new item
        // how do we check this?
        // use the isFull method
        if (isFull()){
            cout<<"stack overflow!!"<<endl;
        }
        else{
            top++;
            arr[top] = val;
        }
    }

    int pop(){
        if(isEmpty()){  //always check if the stack contains any items or not
            cout<<"Stack underflow."<<endl;
            return 0;
        }else{
            int popValue = arr[top]; //first output the popped item
            arr[top] = 0;//secondly delete the said popped item
            top--; // after that change the value of the top variable
            return popValue;
        }

    }

    int count(){
        return(top+1);
    }

    int peek(int index_position){
        if(isEmpty()){
            cout<<"Stack underflow."<<endl;
            return 0; 
        }else{
            return arr[index_position];
        }
    }

    void change(int index_position, int updated_value){
        arr[index_position] = updated_value;
        cout<<"Item at position no. "<<index_position<<" changed to: "<<updated_value<<endl;
    }

    void display(){
        cout<<"All values in the stack are:"<<endl;
        //print values in ascending order
        for(int i=4; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }
    
};

int main(){
    Stack s1;  //create a stack object by the name s1
    
    int option, position, value;
    //create an 8-item menu 
    // for each option no. selected, the stack performs sth.

    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl << endl;
        //but this is just what you see on the screen
        //implement a switch case to actually give these above options some meaning and make them do sth correspondingly

        cin>>option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout<<"Enter a value/item that you wanna push into the stack: "<<endl;
            cin>>value;
            s1.push(value);
            break;
        
        case 2:
            cout<<"Item popped from the stack is: "<<s1.pop()<<endl;
            break;

        case 3:
            if(s1.isEmpty()){
                cout<<"Stack is empty."<<endl;
            }else{
                cout<<"Stack is not empty."<<endl;
            }
            break;

        case 4:
            if(s1.isFull()){
                cout<<"Stack is full."<<endl;
            }else{
                cout<<"Stack is not full."<<endl;
            }
            break;

        case 5:
            cout<<"Which position item do you wanna peek at? Enter: "<<endl;
            cin>>position;
            cout<<"Item at position no. "<< position <<" is: "<<s1.peek(position)<<endl;
            break;

        case 6:
            cout<<"Total no. of items in the stack is: "<<s1.count()<<endl;
            break;
        case 7:
            cout<<"Which position item do you wanna change? Enter: "<<endl;
            cin>>position;
            cout<<"What is the new value at this position? Enter: "<<endl;
            cin>>value;
            s1.change(position, value);
            cout<<"Item at position no. "<< position <<" has been changed to: "<<value<<endl;
            break;

        case 8:
            cout<<"display() fx called."<<endl;
            s1.display();
            break;

        case 9:
            system("cls");
            break;

        default:
            cout<<"Enter proper option no."<< endl;
        }


    } while (option != 0);  //do...while loop ensures that menu-driven program is exited if user presses 0
    

    return 0;
 }