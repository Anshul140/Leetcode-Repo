class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> sans;
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i = 0; i<n-2; i++) {
            for(int j = i+1; j<n-1; j++) {
                int lsum = nums[i]+nums[j];
                int rsum = (-1)*lsum;
                // cout<<"i: "<<i<<" j: "<<j<<endl;
                // cout<<"sum: "<<rsum<<endl;
                auto it = lower_bound(nums.begin()+j+1, nums.end(), rsum);
                
                int idx = it - nums.begin();
                // cout<<"it: "<<it-nums.begin()<<endl;
                if(idx < n and nums[idx] == rsum) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[idx]);
                    // sans.insert(temp);
                    ans.push_back(temp);
                }
                while(j < (n-1) and nums[j] == nums[j+1]) j++;
                // cout<<endl;
            }
            while(i < (n-2) and nums[i] == nums[i+1]) i++;
        }
        
        // for(auto it: sans) ans.push_back(it);
        // cout<<endl;
        return ans;
    }
};