class Solution {
public:
    int n;
    int solve(int i, int j, vector<vector<int>>& dp, string& s) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1 + solve(i+1, j, dp, s);
        
        for(int k = i+1;k<=j; k++) {
            if(s[k] == s[i]) {
                int ans2 = solve(i, k-1, dp, s) + solve(k+1, j, dp, s);
                ans = min(ans, ans2);
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int strangePrinter(string s) {
        n = s.length();
        int ans = n;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, dp, s);
    }
};

/*

abcabcabc

a - 3, b - 3, c - 3
*/