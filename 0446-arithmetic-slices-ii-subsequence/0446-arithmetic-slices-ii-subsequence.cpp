class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<map<long, long>> dp(n+1);
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                long diff = (long)nums[j] - long(nums[i]);
                ans += dp[j][diff];
                dp[i][diff] += dp[j][diff];
                dp[i][diff]++;
            }
        }
        
        return ans;
    }
};