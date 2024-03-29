class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid;
        while(lo <= hi) {
            mid = lo + (hi - lo)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] >= nums[lo]) {
                if(target <= nums[mid] and target >= nums[lo])
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            else {
                if(target >= nums[mid] and target <= nums[hi])
                    lo = mid+1;
                else
                    hi = mid-1;
            }
        }
        return -1;
    }
};