#include <bits/stdc++.h> 
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0]==target);
    if(dp[ind][target] != -1) return dp[ind][target];

    bool dontTake = f(ind-1, target, arr, dp);
    
    bool take = false;
    if(arr[ind]<=target) take = f(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = take or dontTake;
}


bool subsetSumToK(int n, vector<int> &arr){
    vector<bool> prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;
    
    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target<=k; target++){
            bool dontTake = prev[target];
    
            bool take = false;
            if(arr[ind]<=target) take = prev[target-arr[ind]];

            curr[target] = take or dontTake;
        }
        prev = curr;
    }

    return prev[k];
}

bool equalPartition(vector<int>& arr) {
    // code here
    int n = arr.size();
    int total = 0;

    for(int i=0; i<n; i++){
        total = total + arr[i];
    }

    if(total%2 != 0) return false; //odd
    int target = total/2;

   return (subsetSumToK(n, target, arr));
}