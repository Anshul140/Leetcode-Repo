class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> ps(m, vector<long long>(n));

        ps[0][0] = grid[0][0];
        for(int i = 1; i<m; i++) {
            ps[i][0] = ps[i-1][0] + grid[i][0];
        }

        for(int j = 1; j<n; j++) {
            ps[0][j] = ps[0][j-1] + grid[0][j]; 
        }

        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                ps[i][j] = ps[i-1][j] + ps[i][j-1] + grid[i][j] - ps[i-1][j-1];
            }
        }

        for(int i = 0; i<m-1; i++) {
            long long top = ps[i][n-1];
            long long bottom = ps[m-1][n-1] - top;
            if(top == bottom) return true;
        }

        for(int j = 0; j<n-1; j++) {
            long long left = ps[m-1][j];
            long long right = ps[m-1][n-1] - left;
            if(left == right) return true;
        }

        return false;
    }
};