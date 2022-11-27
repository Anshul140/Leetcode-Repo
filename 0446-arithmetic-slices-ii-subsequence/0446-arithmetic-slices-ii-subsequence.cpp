class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<unordered_map<long, long>> dp(n+1);
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                long a = nums[j], b = nums[i];
                long diff = a-b;
                ans += dp[j][diff];
                dp[i][diff] += dp[j][diff];
                dp[i][diff]++;
            }
        }
        
        return ans;
    }
};