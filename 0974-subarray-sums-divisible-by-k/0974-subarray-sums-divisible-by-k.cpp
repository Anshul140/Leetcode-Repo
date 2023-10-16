class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int ps = 0;
        map<int, int> mp;
        mp[0] = 1;
        
        for(int i = 0;i<n; i++) {
            ps += nums[i];
            int rem = ps%k;
            if(rem < 0) rem += k;
            
            if(mp.count(rem)) ans += mp[rem];
            mp[rem]++;
        }
        
        return ans;
    }
};
/*
4, 5, 0, -2, -3, 1
k = 5

ans = 6, mp[0] = 1
mp[4] = 3, mp[2] = 1, 

i = 0, ps = 4, rem = 4 ans = 0
i = 1, ps = 9, rem = 4 ans = 1
i = 2, ps = 9, rem = 4 ans = 3
i = 3, ps = 7, rem = 2 ans = 3
i = 4, ps = 4, rem = 4 ans = 6
i = 5, ps = 5, rem = 0 ans = 7

*/