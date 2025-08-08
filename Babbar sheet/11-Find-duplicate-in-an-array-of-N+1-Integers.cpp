// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int duplicateFinder(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[arr[i]%n] = arr[arr[i]%n] + n;
    }
     for(int i=0; i<n; i++){
         if(arr[i]/n > 1){
             cout<<i<<endl;
         }
    }
}


int main(){
    int arr[] = {3,1,3,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    duplicateFinder(arr, n);
}