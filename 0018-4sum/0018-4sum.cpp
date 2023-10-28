class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> sv;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        if(n < 4) return ans;
        
        int sum = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                long long x = target, y = nums[i], z = nums[j];
                long long tt = x - (y + z);
                map<long, int> mp;
                
                for(int k = j+1; k<n; k++) {
                    vector<int> temp;
                    if(mp.count(tt - nums[k])) {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(tt - nums[k]);
                        sv.insert(temp);
                        sum++;
                    }
                    mp[nums[k]] = k;
                }
            }
        }
        // cout<<"sum: "<<sum<<endl;
        for(auto it: sv) ans.push_back(it);
        return ans;
    }
};