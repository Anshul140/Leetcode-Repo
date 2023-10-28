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
                
                int l = j+1, r = n-1;
                while(l < r) {
                    if(nums[l] + nums[r] < tt) l++;
                    else if(nums[l] + nums[r] > tt) r--;
                    else {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        sv.insert(temp);
                        l++;
                        r--;
                    }
                }
            }
        }
        // cout<<"sum: "<<sum<<endl;
        for(auto it: sv) ans.push_back(it);
        return ans;
    }
};