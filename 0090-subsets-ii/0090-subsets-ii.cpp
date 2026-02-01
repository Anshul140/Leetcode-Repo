class Solution {
public:
    vector<vector<int>> subsets;
    int n;

    void generate(int start, vector<int>& nums, vector<int>& temp) {
        subsets.push_back(temp);

        for(int i = start; i<nums.size(); i++) {
            if(i > start and nums[i-1] == nums[i]) continue;

            temp.push_back(nums[i]);
            generate(i+1, nums, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        generate(0, nums, temp);

        // vector<vector<int>> ans;
        // for(auto it: subsets) {
        //     ans.push_back(it);
        // }

        return subsets;
    }
};