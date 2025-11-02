class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int last = n-1, first = 0, ct = 0;

        for(int el: nums) if(el == val) ct++;

        while(first < (n-ct)) {
            if(nums[first] == val) {
                while(last >= first and nums[last] == val) last--;

                swap(nums[first], nums[last]);
            }

            first++;
        }

        return n-ct;
    }
};