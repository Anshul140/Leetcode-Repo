class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                int l = j+1, r = n-1;
                long long int x = nums[i], y = nums[j];
                long long int rem = target - (x+y);
                while(l < r) {
                    if(nums[l] + nums[r] == rem) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        
                        while(l < r and nums[l] == nums[l+1]) l++; 
                        while(l < r and nums[r] == nums[r-1]) r--; 
                        l++; 
                        r--;
                    } else if(nums[l] + nums[r] < rem){
                        l++;
                    } else {
                        r--;
                    }
                }
                
                while(j < n-1 and nums[j] == nums[j+1]) j++;
            }
            while(i < n-1 and nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};