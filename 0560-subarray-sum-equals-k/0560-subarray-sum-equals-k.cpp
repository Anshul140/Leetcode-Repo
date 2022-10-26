class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        
        mp[0] = 1;
        int ps = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            ps += nums[i];
            if(mp.count(ps - k)) {
                ans += mp[ps - k];   
            }
           
            mp[ps]++;
        }
        
        return ans;
    }
};