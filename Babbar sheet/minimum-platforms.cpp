 int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int totalPlatformsBeingUsed = 1;

        int i = 1;
        int j = 0;

        while(i<n){
            if(arr[i]<=dep[j]){
                totalPlatformsBeingUsed++;
            }else j++;
            i++;
        }

        return totalPlatformsBeingUsed;

    }