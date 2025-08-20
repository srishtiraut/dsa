class Solution {
  public:
    void floydWarshall(vector<vector<int>> &matrix) {
        int n = matrix.size();
        const int INF = 100000000; // 1e8

        // Ensure self-distances = 0
        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != INF && matrix[k][j] != INF) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
    }
};
