class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ps(n, vector<int>(m));

        ps[0][0] = grid[0][0];
        int ans = 0;
        if(ps[0][0] <= k) ans++;

        for(int i = 1; i<n; i++) {
            ps[i][0] = ps[i-1][0] + grid[i][0];
            if(ps[i][0] <= k) ans++;
        }

        for(int j = 1; j<m; j++) {
            ps[0][j] = ps[0][j-1] + grid[0][j];
            if(ps[0][j] <= k) ans++;
        }

        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                ps[i][j] += grid[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
                if(ps[i][j] <= k)
                    ans++;
            }
        }

        return ans;
    }
};