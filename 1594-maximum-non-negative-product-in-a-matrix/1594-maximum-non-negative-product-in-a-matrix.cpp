class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long mod = 1e9+7;
        vector<vector<long long int>> dp_min(m, vector<long long int>(n, LONG_LONG_MAX));
        vector<vector<long long int>> dp_max(m, vector<long long int>(n, LONG_LONG_MIN));

        dp_min[0][0] = dp_max[0][0] = grid[0][0];

        for(int i=1; i<m; i++) {
            dp_min[i][0] = min(dp_min[i][0], dp_min[i-1][0] * grid[i][0]);
            dp_max[i][0] = max(dp_max[i][0], dp_max[i-1][0] * grid[i][0]);
        }

        for(int i=1; i<n; i++) {
            dp_min[0][i] = min(dp_min[0][i], dp_min[0][i-1] * grid[0][i]);
            dp_max[0][i] = max(dp_max[0][i], dp_max[0][i-1] * grid[0][i]);
        }

        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                long long a1 = dp_min[i-1][j] * grid[i][j];
                long long a2 = dp_max[i-1][j] * grid[i][j];
                long long a3 = dp_min[i][j-1] * grid[i][j];
                long long a4 = dp_max[i][j-1] * grid[i][j];

                dp_min[i][j] = min({a1, a2, a3, a4});
                dp_max[i][j] = max({a1, a2, a3, a4});
            }
        }

        long long ans = max(dp_max[m-1][n-1], dp_min[m-1][n-1]);
        if(ans < 0) return -1;

        return ans%mod;
    }
};