class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        queue<int> q;
        q.push(0);

        int color[V];

        for(int i=0; i<V; i++) color[i] = -1;
        color[0] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto neighbor: adj[node]){
                if(color[neighbor]!=1 || color[neighbor]!=0){
                    color[neighbor] = !color[node];
                    q.push(neighbor);
                }else if(color[neighbor] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
};