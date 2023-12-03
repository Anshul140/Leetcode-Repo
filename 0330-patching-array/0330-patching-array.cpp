class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long int mxr = 0, ans = 0, sz = nums.size();

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