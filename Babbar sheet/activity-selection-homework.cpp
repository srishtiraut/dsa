    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }   
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        //make a new vector of pairs(startTime, endTime)
        vector<pair<int, int>> startEndPairs;
        int totalActivitiesPossible = 1;
    
        //put elements from start[] and end[] into startEndPairs
        for(int i=0; i<n; i++){
            pair<int, int> ithPair = make_pair(start[i], end[i]);
            startEndPairs.push_back(ithPair);
        }
    
        //sort this startEndPairs vector in increasing order of endTime
        sort(startEndPairs.begin(), startEndPairs.end(), cmp);
    
        //traverse through startEndPairs vector.
        int starterSecond = startEndPairs[0].second;
        for(int i=1; i<n; i++){
            //pick each pair and check
            if(startEndPairs[i].first > starterSecond){
                totalActivitiesPossible++;
                starterSecond = startEndPairs[i].second;
            }
        }
        return totalActivitiesPossible;
        }