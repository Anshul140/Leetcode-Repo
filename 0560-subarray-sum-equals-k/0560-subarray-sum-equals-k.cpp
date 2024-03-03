class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        map<int, int> mp;
        mp[0] = 1;
        
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            if(mp.count(sum - k)) ans += mp[sum-k];
            mp[sum]++;
        }
        
        return ans;
    }
};