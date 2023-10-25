class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        map<int, set<int>> mp;
        
        for(int i = 0;i<n; i++) {
            if(mp.count(target-nums[i])) {
                ans.push_back(i);
                ans.push_back(*mp[target-nums[i]].begin());
                return ans;
            }
            mp[nums[i]].insert(i);
        }
        
        return ans;
    }
};