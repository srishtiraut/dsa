/*
Problem no.: 18 Find all pairs on integer array whose sum is equal to given number
Given: an array of N integers, 
        and an integer K, 
To-find:  how many pairs of elements in the array have sum equal to K.

My approach: traverse and look at each element of the array
if k - arr[i] exists in the array, then increment count
*/

#include <bits/stdc++.h>
using namespace std;

/*
Naive Solution – A simple solution is to traverse each element and check if there’s another number in the array which can be added to it to give sum. 
Has Time Complexity: O(n^2) and Auxiliary Space: O(1)
*/

int getPairsCount(int arr[], int n, int sum){

    int count = 0;

    // Consider all possible pairs and check their sums
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j] == sum){
                count++;
            }
        }
    }
    return count;
}

/*Efficient solution -  is possible in O(n) time by using map */
int efficient_getPairsCount(int arr[], int n, int k){

    int count = 0;

    //Create an unordered map to store frequency of each number in the array. (Single traversal is required)
    unordered_map<int, int> m; // Declaring m to be of <int, int> type jiska key and mapped value will be of int type each
    for(int i=0; i<n;i++){//Store count of all elements in unordered map m
        if(m.find(k-arr[i]) != m.end()){
            count = count + m[k-arr[i]];
    }
    m[arr[i]]++;  //increasing the value corresp to this key
    }
    return count;
}


int main()
{
    int arr[] = { 1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    cout << "Count of pairs is "<< getPairsCount(arr, n, sum)<<endl;
    cout<<"Count of pairs in O(n) = " << efficient_getPairsCount(arr, n, sum);
    return 0;
}


// OUTPUT:
// C:\Users\SRISHTI\Desktop\DSA\450 questions>a
// Count of pairs is 3
// Count of pairs in O(n) = 3


