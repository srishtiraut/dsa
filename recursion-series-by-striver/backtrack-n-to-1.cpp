#include <iostream>
using namespace std;

void printNumsReverse(int i, int n){
    //base case
    if(i>n) return;
    
    printNumsReverse(i+1, n);
    cout<<i;
}

int main(){
   int n;
   cin>>n;
   printNumsReverse(1,n);
}