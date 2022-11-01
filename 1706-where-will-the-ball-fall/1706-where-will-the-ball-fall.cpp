class Solution {
public:
    int r, c;
    int dfs(int i, int j, vector<vector<int>>& grid, int& curr) {
        if(i > r-1) {
            curr = j;
            return 1;
        }
        if(i < 0 or j < 0 or j > c-1)
            return 0;
        if(j < c-1 and grid[i][j] == 1 and grid[i][j+1] == -1)
            return 0;
        if(j > 1 and grid[i][j] == -1 and grid[i][j-1] == 1)
            return 0;
        if(j == c-1 and grid[i][j] == 1)
            return 0;
        if(j == 0 and grid[i][j] == -1)
            return 0;
        
        int ans = 1;
        if(grid[i][j] == 1)
            ans &= dfs(i+1, j+1, grid, curr);
        else
            ans &= dfs(i+1, j-1, grid, curr);
        
        return ans;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        
        int curr = 0;
        vector<int> ans(c, -1);
        for(int i = 0; i<c; i++)
            if(dfs(0, i, grid, curr) == 1) {
                ans[i] = curr;
                curr = 0;
            }
        
        return ans;
    }
};