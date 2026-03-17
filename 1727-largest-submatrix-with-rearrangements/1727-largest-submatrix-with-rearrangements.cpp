class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) {
                    grid[i][j] += grid[i-1][j];
                }
            }
        }        
       
        int ans = 0;
        for(int i = 0; i<n; i++) {
            sort(grid[i].begin(), grid[i].end());
            reverse(grid[i].begin(), grid[i].end());

            for(int j = 0; j<m; j++) {
                ans = max(ans, (j+1)*grid[i][j]);
            }
        }

        return ans;
    }
};