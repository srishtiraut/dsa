/* https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

Given an array arr[] and an integer K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array.
It is given that all array elements are distinct.
*/


//It is Quickselect Algorithm basically
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Standard partition process of QuickSort().
// It considers the last element as pivot and moves all smaller element to left of it and greater elements to right
int partition(int arr[], int left, int right){
    
    for(int j = left; j < right; j++){
        if(arr[j] <= arr[right]){  //if leftmost element <= rightmost element, swap
            swap(arr[left],arr[j]);
            left++;
        }
     }
    swap(arr[left],arr[right]);
    return left;

}

int kthSmallest(int arr[], int left, int right, int k){  // This function returns k'th smallest element in arr[l..r] using QuickSort based method. 
                                                  // ASSUMPTION: ALL ELEMENTS IN arr[] ARE DISTINCT

if(k>0 && k <= right - left + 1){
    // Partition the array around last element and get position of pivot element in sorted array
    int index = partition(arr,left,right);
    if(index-left == k-1)
        return arr[index];
    if(index-left > k-1)
        return kthSmallest(arr, left, index - 1, k);
    return kthSmallest(arr, index + 1, right, (k - index + left - 1));
    
}
return INT_MAX;

}

int main(){
    int arr[] = {7,10,4,3,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    cout << "K-th smallest element = "<< kthSmallest(arr, 0, n - 1, k);
    return 0;
}