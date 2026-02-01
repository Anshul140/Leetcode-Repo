class Solution {
public:
    set<vector<int>> subsets;
    int n;

    void generate(int i, vector<int>& nums, vector<int> temp) {
        if(i == n) {
            sort(temp.begin(), temp.end());
            subsets.insert(temp);
            return;
        }

        temp.push_back(nums[i]);
        generate(i+1, nums, temp);

        temp.pop_back();
        generate(i+1, nums, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        generate(0, nums, temp);

        vector<vector<int>> ans;
        for(auto it: subsets) {
            ans.push_back(it);
        }

        return ans;
    }
};