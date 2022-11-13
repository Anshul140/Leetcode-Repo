#define ll long long int
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        int n= nums.size();
        for(int i = 0; i<n; i++) {
            int lcm = nums[i];
            if(lcm == k) ans++;

            for(int j = i+1; j<n; j++) {
                int hcf = __gcd(lcm, nums[j]);
                lcm = (lcm * nums[j])/hcf;

                if(lcm > k) break;
                if(lcm == k) ans++;
            }
        }
        return ans;
    }
};