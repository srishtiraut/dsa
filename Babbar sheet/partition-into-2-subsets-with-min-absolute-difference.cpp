int minSubsetSumDifference(vector<int>& arr, int n){
    //declare and initialize total
    int total = 0;
    for(int i=0; i<n; i++) total += arr[i];

    int k = total;

    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int i=0; i<n; i++) dp[i][0] = true;
    
    if(arr[0]<=k) dp[0][arr[0]] = true;

    for(int ind=1; ind<n; ind++){
        for(int target=1; target<=k; target++){
            bool noTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = take or noTake;
        }
    }
    //dp[n-1][col 0 to total]
    int mini = 1e9;
    for(int s1=0; s1<=total/2; s1++){
        if(dp[n-1][s1]==true){
            mini = min(mini, abs((total-s1)-s1));       //total - s1= s2
        }
    }
    return mini;
}