class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == 1)
            return false;
        unordered_map<int, int> mp;
        
        long int ps = 0;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
            ps += nums[i];
            if(mp.count(ps % k)) {
                if((i - mp[ps%k]) > 1)
                   return true;
            }
            else
                mp[ps % k] = i;    
        }
        
        return false;
    }
};