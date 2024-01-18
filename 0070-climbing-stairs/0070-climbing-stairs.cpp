class Solution {
public:
    vector<int> dp;
    Solution() {
        dp.resize(50, -1);
    }
    
    int climbStairs(int n) {
        if(n <= 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = climbStairs(n-2) + climbStairs(n-1);
    }
};