#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int index) {
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
void reverse(int arr[], int i, int j) {
        while (i < j) {
            swap(arr, i, j);
            i++;
            j--;
        }
    }

int nextPermutation(int arr[], int size){
    int index,j;
// Scan the array from right to left until an element is found which is smaller than the index at its right. Mark the index of such element as index.
for(int i=size; i>0; i--){
    if(arr[i-1] < arr[i]){
        index = i-1;
        break;
    }
}
// Again scan the array from right to left until an element is found which is greater than the element found in the above step. Mark the index of such elements as j.
for(int i=size; i>0; i--){
    if(arr[i] > arr[index]){
        j = i;
    }
}
// Swap the two elements at indices index and j.
swap(arr,j, index);
// Now, reverse the array from index index until the end of the array.
cout<<reverse(arr, index+1, size-1);


}



int main(){
    int arr[] = {4,5,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    return nextPermutation(arr, size);
}