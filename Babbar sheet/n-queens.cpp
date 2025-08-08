class Solution {

    void addSolution(vector<vector<int>> & ans, vector<int> &board, int n){
        vector<int> temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        int x = row;
        int y = col;

        //check for same row
        while(y>=0){
            if(board[x][y]==1) return false;
            y--;
        }
        //check for upperLeft diagonal and lowerLeft diagonal
         x = row;
         y = col;
         while(x>=0 and y>=0){      //upperLeft
            if(board[x][y]==1) return false;
            y--;
            x--;
         }
         x = row;
         y = col;
         while(x<n and y>=0){      //lowerLeft
            if(board[x][y]==1) return false;
            y--;
            x++;
         }
        //no need to check for same column
        //if all three ifs were passed, means it is safe to place a Queen
        return true;
    }

    void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
        //base case
        if(col==n){     //all cols filled
            //fill ans with the solution held by board
             addSolution(ans, board, n);
             return;
        }
        //solve 1 case and the rest is solved by recursion
        //place Q1 in first column
        for(int row=0; row<n; row++){       //check for each row of the col.
            if(isSafe(row, col, board, n)){
                //it is safe, so place a Queen
                board[row][col] = 1;
                solve(col+1, ans, board, n);
                //backtrack karlo
                //means remove placed queen
                board[row][col] = 0;

            }
        }

    }

    public:
      vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>> ans;

        solve(0, ans, board, n);

        return ans;

      }
  };