class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int val = n+1;
        
        for(int i = 0; i<n; i++) {
            nums[(nums[i]%val)-1] = nums[(nums[i]%val)-1]+val;
        }
        
        for(int i = 0; i<n; i++) {
            if(nums[i]/val > 1) ans.push_back(i+1);
        }
        
        return ans;
    }
};