class Solution {
public:
    const long long int mod = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 1));

        long long p = 1, s = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans[i][j] = p;
                p *= grid[i][j];
                p %= mod;
            }
        }

        for(int i = n-1; i>=0; i--) {
            for(int j = m-1; j>=0; j--) {
                ans[i][j] *= s;
                ans[i][j] %= mod;

                s *= grid[i][j];
                s %= mod;
            }
        }

        return ans;
    }
};