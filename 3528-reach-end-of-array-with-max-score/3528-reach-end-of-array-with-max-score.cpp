class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
    
        long long ans = 0, last_idx = 0, last = nums[0];
        
        for(long long i = 1; i<n; i++){
            ans += last;
            last = max(last, (long long)nums[i]);
        }
        
        return ans;
    }
};