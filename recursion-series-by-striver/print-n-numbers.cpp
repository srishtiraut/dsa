#include <iostream>
using namespace std;

void printNums(int i, int n){
    //base case
    if(i>n) return;
    cout<<i<<"\n";
    i++;
    printNums(i,n);
}

int main(){
   int n;
   cin>>n;
   printNums(1,n);
}