class Solution {
  public:

    void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&vis, vector<pair<int, int>>&shape, int baseRow, int baseCol){
        
        int n = grid.size();
        int m = grid[0].size();
               
        vis[row][col] = 1;
        shape.push_back({row-baseRow, col-baseCol});

        //for neighbors of row, col call dfs

        int delRow = {-1,0,1,0};
        int delCol = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow<n && nrow>=0 && ncol>m && ncol<=0 &&
            grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis, shape, baseRow, baseCol );
            }
        }
    
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int, int>> shape;
                    dfs(i, j, grid, vis, shape, i, j);
                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};