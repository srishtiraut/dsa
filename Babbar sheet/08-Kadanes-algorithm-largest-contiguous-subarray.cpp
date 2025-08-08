//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

#include<iostream>
#include<climits>
using namespace std;


//[2,3,-5,7,3,-12,2,4]
int maxSubArraySum(int arr[], int n){
    int max_so_far = INT_MIN, max_ending_here = 0;
    for(int i=0; i<n; i++){
        max_ending_here = max_ending_here + arr[i];
        if(max_ending_here > max_so_far)
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;

    }
    return max_so_far;
}

int main(){
    int arr[] = {-2, 3, 2, -1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxSum= maxSubArraySum(arr, n);
    cout<<maxSum;
}