#include <iostream>
using namespace std;

void f(int i, int n, int sum){
    //base case
    if(i>n) {
        cout<<sum;
        return;
    }
    f(i+1, n, sum+i);
    
}

int main(){
   int n, sum;
   cin>>n;
   f(1,n,0);
   return 0;
}