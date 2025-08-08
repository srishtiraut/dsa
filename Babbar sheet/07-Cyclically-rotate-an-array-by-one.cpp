// 1) Store last element in a variable say x. 
// 2) Shift all elements one position ahead. 
// 3) Replace first element of array with x.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int rotateArray(int arr[], int n){
    int temp = arr[n-1];
    int i = n-1, j = 1;
    while(i>0){
        arr[i] = arr[i-1];
        i--;
        
    }
    arr[0] = temp;
    printArray(arr,n);
}

int main(){
    
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    rotateArray(arr, n);
}
 