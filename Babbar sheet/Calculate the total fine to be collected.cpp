#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findFine(int arr[], int n, int date){
    int count = 0, fineTotal = 0;
    //traverse the loop
    for(int i=0;i<n;i++){
        if( (date%2 != 0 && arr[i]%2 != 0) || (date%2 == 0 && arr[i]%2 == 0) ){
            continue;
        }else{
            count++;
        }
    }

    fineTotal = count*250;
    cout<<fineTotal;

}

int main(){
    int arr[] = {3, 4, 1, 2};
    int date = 15;
    int n = sizeof(arr)/sizeof(arr[0]);
    findFine(arr,n,date);
}