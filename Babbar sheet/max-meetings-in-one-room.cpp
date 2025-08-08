static bool cmp(pair<int, int> a, pair<int, int> b){
        //case where two meetings can be chosen for the same slot 
        //then choose meeting that finishes earlier.
        if(a.first.second == b.first.second) 
            return a.first.first < b.first.first;
        
        return a.first.second < b.first.second;
    }   
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    vector<int> maxMeetings(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        //make a new vector
        vector<pair<pair<int, int>, int> startEndPairsWithOriginalIndices; 
        //format: ((startTime, endTime), originalIndex)
       
        vector<int> arrayOfPossibleMeetings;
    
        //put elements from start[] and end[] into startEndPairsWithOriginalIndices
        for(int i=0; i<n; i++){
            //pair<int, int> ithPair = make_pair();
            startEndPairsWithOriginalIndices.push_back({{start[i], end[i]}, i+1});
        }
    
        //sort this startEndPairs vector in increasing order of endTime
        sort(startEndPairsWithOriginalIndices.begin(), startEndPairsWithOriginalIndices.end(), cmp);
    
        
        int starterEndTime = startEndPairsWithOriginalIndices[0].first.second;
        //store index of the 0th meeting into ans array because at least that one meeting is always possible
        arrayOfPossibleMeetings.push_back(startEndPairsWithOriginalIndices[0].second);
        
        //traverse through startEndPairsWithOriginalIndices vector.
        for(int i=1; i<n; i++){
            //pick each pair and check
            if(startEndPairsWithOriginalIndices[i].first.second > starterEndTime){
                //include meeting number
                arrayOfPossibleMeetings.push_back(startEndPairsWithOriginalIndices[i].second);
                starterEndTime = startEndPairsWithOriginalIndices[i].first.second;
            }
        }
        sort(arrayOfPossibleMeetings.begin(), arrayOfPossibleMeetings.end());
        return arrayOfPossibleMeetings;
        }

        class Solution {
public:
    static bool comp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
        if (a.first.second == b.first.second)
            return a.first.first < b.first.first;
        return a.first.second < b.first.second;
    }

    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        vector<int> ans;
        vector<pair<pair<int, int>, int>> meetings;  // To store meeting times along with their original indices

        for(int i = 0; i < N; i++){
            meetings.push_back({{S[i], F[i]}, i + 1});
        }

        sort(meetings.begin(), meetings.end(), comp);

        int lastEndTime = meetings[0].first.second;
        ans.push_back(meetings[0].second);

        for(int i = 0; i < N; i++){
            if(meetings[i].first.first > lastEndTime){
                lastEndTime = meetings[i].first.second;
                ans.push_back(meetings[i].second);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<pair<int , int>, int>> v;
        for(int i = 0; i < N; i++)
            v.push_back({{F[i], S[i]}, i+1});
        sort(v.begin(), v.end());
        vector<int> ans;
        ans.push_back(v[0].second);
        int ansend = v[0].first.first;
        for(int i = 1; i < N; i++){
            if(v[i].first.second > ansend){
                ans.push_back(v[i].second);
                ansend = v[i].first.first;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

--------