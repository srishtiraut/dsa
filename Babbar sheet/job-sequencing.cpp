static bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n){
    int maxDaysNeededForAllJobs = INT_MIN;
    
    //sort in descending order of profit
    sort(arr, arr+n, cmp);

    //find maxDaysNeededForAllJobs
    for(int i=0; i<n; i++){
        maxDaysNeededForAllJobs = max(maxDaysNeededForAllJobs, arr[i].dead);
    }

    vector<int> daysForExecution(maxDaysNeededForAllJobs+1, -1); //initialize with -1
    int numOfJobsDone = 0;
    int totalProfit = 0;

    //traverse sorted arr
    for(int i=0; i<n; i++){
        int currProfit = arr[i].profit;
        int currJobId = arr[i].id;
        int currDeadline = arr[i].dead;

        //can i complete current job right now?
        for(int k=currDeadline; k>0; k--){
            if(daysForExecution[k] == -1){
                //means job can be done
                numOfJobsDone++;
                totalProfit = totalProfit + currProfit;
                daysForExecution[k] = currJobId;
                break;
            }
        }
    }
    vector<int> ansVector;
    ans.push_back(numOfJobsDone);
    ans.push_back(totalProfit);

    return ansVector;
}