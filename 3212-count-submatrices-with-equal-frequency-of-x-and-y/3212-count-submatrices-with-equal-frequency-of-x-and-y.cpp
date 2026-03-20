class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // prefix sum
        vector<vector<int>> ps(n+1, vector<int>(m+1));

        // cnt of 'X'
        vector<vector<int>> cnt(n+1, vector<int>(m+1));

        unordered_map<char, int> mp;
        mp['X'] = 1;
        mp['Y'] = -1;
        mp['.'] = 0;

        ps[0][0] = mp[grid[0][0]];
        if(grid[0][0] == 'X') cnt[0][0] = 1;

        for(int i = 1; i<n; i++) {
            ps[i][0] += mp[grid[i][0]] + ps[i-1][0];
            if(cnt[i-1][0] or grid[i][0] == 'X') cnt[i][0] = 1;
        }

        for(int i = 1; i<m; i++) {
            ps[0][i] += mp[grid[0][i]] + ps[0][i-1];
            if(cnt[0][i-1] || grid[0][i] == 'X') cnt[0][i] = 1;
        }

        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                ps[i][j] += ps[i-1][j] + ps[i][j-1] + mp[grid[i][j]] - ps[i-1][j-1];
                if(cnt[i-1][j] or cnt[i][j-1] or grid[i][j] == 'X') cnt[i][j] = 1;
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(ps[i][j] == 0 and cnt[i][j]) ans++;
            }
        }

        return ans;
    }
};