//https://www.interviewbit.com/blog/merge-two-sorted-arrays-without-extra-space/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergedAndSorted(int arr1[], int arr2[], int n, int m){
    int i=0, j=0, k=n-1;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
            
        }else{
            swap(arr2[j], arr1[k]);
            j++;
            k--;
        }
    }
    sort(arr1, arr1+n);  /*Here we take two parameters, 
                the beginning of the array and the length n upto which we want the array to be sorted*/
    sort(arr2, arr2+m);

    cout<<"arr1 = ";
    for(int i=0; i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"arr2 = ";
    for(int j=0; j<m; j++){
        cout<<arr2[j]<< " ";
    }
    
}

int main(){
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2,3,8,13};

    int n  = sizeof(arr1)/sizeof(arr1[0]);
    int m  = sizeof(arr2)/sizeof(arr2[0]);

    mergedAndSorted(arr1, arr2, n, m);
    }

/*
C:\Users\SRISHTI\Desktop\DSA\450 questions>g++ 12.cpp

C:\Users\SRISHTI\Desktop\DSA\450 questions>a
arr1 = 1 2 3 5 8 9 
arr2 = 10 13 15 20

*/