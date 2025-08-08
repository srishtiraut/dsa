#include <iostream>
using namespace std;

void printNumsReverse(int i, int n){
    //base case
    if(i<1) return;
    cout<<i;
    printNumsReverse(i-1, n);
}

int main(){
   int n;
   cin>>n;
   printNumsReverse(n,n);
}