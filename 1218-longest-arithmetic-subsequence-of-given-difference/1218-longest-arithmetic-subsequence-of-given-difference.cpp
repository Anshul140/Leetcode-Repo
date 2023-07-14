class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 1;
        
        for(int &el: arr) {
            if(dp.count(el - difference)) {
                int prev = dp[el - difference];
                ans = max(ans, prev+1);
                dp[el] = prev+1;
            } else {
                dp[el] = 1;
            }
        }
        
        return ans;
    }
};