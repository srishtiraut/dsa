#include <iostream>
using namespace std;

void printName(int i, int n){
    //base case
    if(i>n) return;
    cout<<"Srishti loves Aditya hehehehe"<<endl;
    printName(i+1, n);
}

int main(){
   int n;
   cin>>n;
   printName(1,n);
}