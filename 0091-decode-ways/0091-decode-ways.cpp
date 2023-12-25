class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, string& s) {
        if(i == n) return 1;

        if(s[i] == '0') return 0;

        if(dp[i] != -1)
           return dp[i];

        for(int j = i; j<n; j++) {
            if(j+1 < n && s[j] == '1') 
                return dp[i] = solve(j+1, s) + solve(j+2, s);
            else if(j+1 < n && s[j] == '2' && (s[j+1] - '0') < 7) 
                return dp[i] = solve(j+1, s) + solve(j+2, s);
            else
                return dp[i] = solve(j+1, s);
        }

        return dp[i];
    }

    int numDecodings(string s) {
        n = s.size();
        dp.assign(105, -1);
        return solve(0, s);
    }
};