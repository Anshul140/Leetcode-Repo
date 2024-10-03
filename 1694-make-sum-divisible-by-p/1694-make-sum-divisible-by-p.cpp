class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int psum = 0, n = nums.size();
        int sum = 0, ans = n;

        for(int el: nums) {
            sum += el;
            sum %= p;
        }

        map<int, int> mp;
        mp[0] = -1;

        if(sum == 0) return 0;

        for(int i = 0; i<n; i++){
            psum += nums[i];
            psum %= p;
            int find = (psum - sum + p)%p;
            if(mp.count(find)){
                ans = min(ans, i - mp[find]);
            }
            mp[psum] = i;
        }

        return (ans == n)? -1: ans;
    }
};

/*
(total sum - subarray sum) % p == 0
- maximise (total sum - subarray sum)
- subarray sum = p[j] - p[i]
- (tot - (p[j] - p[i]))%p = 0
- (tot - p[j] + p[i])%p = 0
- p[i]%p = (p[j] - tot + p)%p
*/