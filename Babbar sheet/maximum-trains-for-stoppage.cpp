struct comp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[3] <= b[3];
        }
        return a[1] <= b[1];
    }
};

class Solution {
  public:
    int maxStop(int n, int m, vector<vector<int>> &trains) {
        for(int i=0; i<m; i++)
            trains[i].push_back(i);
            
        sort(trains.begin(), trains.end(), comp());
        vector<int> platform(n+1, -1);

        int ans = 0;
        
        for(int i=0; i<m; i++) {
            if(platform[trains[i][2]] <= trains[i][0]) {
                ans++;
                platform[trains[i][2]] = trains[i][1];
            }
        }
        
        return ans;
    }