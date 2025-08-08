class Solution {
    public:

    bool isSafe(int newx, int newy,  vector<vector <bool>> &visited, vector<vector<int>> &arr, int n){
        if((newx>=0 and newx<n) and (newy>=0 and newy<n) and (vsited[newx][newy]!=1 and arr[newx][newy]==1)) return true;
        else return false;
    }

    void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector <bool>> &visited, string path){
        //base case
        if(x==n-1 and y=n-1){
            //means destination reached. So, store ans and return.
            ans.push_back(path);        
            return;
        }

        //4 movements are possible - D L R U ...alphabetically aka lexicographically
        visited[x][y] = 1;
        
        if(isSafe(x+1, y, visited, arr, n)){       // Down
            solve(x+1, y, arr, n, ans, visited, path+'D');  //function call for new cell, i.e, new x and new y
        }
        if(isSafe(x, y-1, visited, arr, n)){       // Left
            solve(x-1, y-1, arr, n, ans, visited, path+'L');  //function call for new cell, i.e, new x and new y  
        }
        if(isSafe(x, y+1, visited, arr, n)){       // Right
            solve(x, y+1, arr, n, ans, visited, path+'R');  //function call for new cell, i.e, new x and new y  
        }
        if(isSafe(x-1, y, visited, arr, n)){       // Up
            solve(x-1, y, arr, n, ans, visited, path+'U');  //function call for new cell, i.e, new x and new y 
        }

        visited[x][y] = 0; 
    }


    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n  = mat.size();
        vector<string> ans;
        vector<vector <bool>> visited (n, vector <bool>(n,0));

        string path = "";

         //edge case
         if(mat[0][0]==0) return ans;       // rat is standing on a blocked 0,0 cell


        solve(0, 0, mat, n, ans, visited, path);
        return ans;
    }
  };