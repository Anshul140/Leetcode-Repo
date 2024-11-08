long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mxb) {
        int n = nums.size();
        vector<int> ans(n);

        int req = binpow(2, mxb)-1, cur = 0;
        for(int i = 0; i<n; i++) {
            cur ^= nums[i];
            ans[n-i-1] = cur^req;
        }

        return ans;
    }
};