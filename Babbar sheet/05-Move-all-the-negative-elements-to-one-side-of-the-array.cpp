#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printarray(int arr[], int n){
    for(int i=0;i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int segregateNegatives(int arr[], int n){
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]<0){           
            if (i != j){
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}

int main(){

    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr)/sizeof(arr[0]);

    segregateNegatives(arr, n);
    printarray(arr, n);

return 0;
}