//https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

#include <bits/stdc++.h>
using namespace std;

int minJumpsFunction(int arr[], int n){
    if(n==1){
        return 0;
    }
    int minimumJumps = INT_MAX;

    for(int i=n-2; i>=0; i--){
        if(i+arr[i] >= n-1){
            int subResult = minJumpsFunction(arr, i+1);
            if(subResult != INT_MAX)
                minimumJumps = min(minimumJumps, subResult+1);
        }
    }

    return minimumJumps;
}

int main()
{
    int arr[] = { 1, 3, 6, 3, 2, 3, 6, 8, 9, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to reach the end is " << minJumpsFunction(arr, n);
    return 0;
}