class Solution {
public:
    int r, c, n;
    int dp[102][2050];
    map<int, vector<int>> mp;
    vector<int> v;

    int solve(int i, int mask) {
        if(i >= n) return 0;

        if(dp[i][mask] != -1) return dp[i][mask];

        int ans = 0;
        for(auto el: mp[v[i]]){
            int elMask = 1 << el;
            if(!(elMask & mask)){
                // if not visited
                int newVis = mask | (1 << el);
                ans = max(ans, v[i] + solve(i+1, newVis));
            }
        }

        ans = max(ans, solve(i+1, mask));
        return dp[i][mask] = ans;
    }

    int maxScore(vector<vector<int>>& mat) {
        r = mat.size();
        c = mat[0].size();
        v.clear();
        mp.clear();
        memset(dp, -1, sizeof(dp));

        set<int, greater<int>> s;
        for(auto vec: mat){
            for(auto el: vec) s.insert(el);
        }

        for(auto it: s) v.push_back(it);
        n = v.size();

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++) {
                mp[mat[i][j]].push_back(i);
            }
        }

        return solve(0, 0);
    }
};