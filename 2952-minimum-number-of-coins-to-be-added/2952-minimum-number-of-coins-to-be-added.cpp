class Solution {
public:
    int minimumAddedCoins(vector<int>& nums, int n) {
        long int mxr = 0, ans = 0, sz = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] <= mxr+1) {
                mxr += nums[i];
            } else {
                while(mxr < n and nums[i] > mxr+1) {
                    mxr += (mxr+1);
                    ans++;
                }
                mxr += nums[i];
            }
        }
        
        while(mxr < n) {
            ans++;
            mxr += (mxr+1);
        }
        return ans;
    }
};