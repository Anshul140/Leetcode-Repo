class Solution {
public:
    int solve(set<int>& arr) {
        if(arr.size() == 1) return 0;
        int ans = INT_MAX;

        int itr = 0;
        int last = 0;
        for(auto el: arr) {
            if(itr == 0) {
                itr++;
                last = el;
                continue;
            }

            ans = min(ans, abs(last - el));
            last = el;
        }

        return ans;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int al = m-k+1, ab = n-k+1;

        vector<vector<int>> ans(al, vector<int>(ab));

        for(int i = 0; i<(m-k+1); i++) {
            for(int j = 0; j<(n-k+1); j++) {
                set<int> cur;
                for(int x = i; x<m && x<=(i+k-1); x++) {
                    for(int y = j; y<n && y<=(j+k-1); y++) {
                        cur.insert(grid[x][y]);
                    }
                }

                if(cur.size() == 0) continue;
                int res = solve(cur);
                ans[i][j] = res;
            }
        }

        return ans;
    }

};