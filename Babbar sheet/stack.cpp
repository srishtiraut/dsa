#include<iostream>
// #include<stack>
using namespace std;

class Stack{
    public:
    //properties
    int* arr;
    int top;
    int size;

    //behaviour
    Stack(int size){    //constructor to create stack objects of size=size
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    //methods
    void push(int element){
        //push only if space is available
        if(size-top > 1){
            top++;
            arr[top] = element;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop(){
        //pop only if stack has at least one element
        if(top>=0){   
            cout<<arr[top]<<endl;
            top--;
        }else{
            cout<<"Stack underflow"<<endl;
        }

    }

    int peek(){

        if(top>=0)
            return arr[top];
        else{
            cout<<"Stack empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }

};


int main(){
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    st.pop();
    st.pop();
    st.pop();



































//     stack<int> s;

//     //insert elements in stack
//     s.push(2);
//     s.push(10);
//     cout<<s.size()<<endl;

//     //pop operation
//     s.pop();
//     cout<<"s.top()= "<< s.top()<<endl ;

// s.pop();
//     if(s.empty())
//         cout<<"empty";
//     else
//         cout<<"not empty";
 
    return 0;
}