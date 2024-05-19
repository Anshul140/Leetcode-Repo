class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n1 = nums.size();
        int n2 = queries.size();
        
        if(n1 == 1){
            vector<bool> ans(n2, true);
            return ans;
        }
        
        vector<int> pref(n1);
        pref[0] = (nums[0]%2 == nums[1]%2)?1:0;
        for(int i = 1; i<n1-1; i++) {
            if(nums[i]%2 == nums[i+1]%2) pref[i] += 1 + pref[i-1];
            else pref[i] += pref[i-1];
        }
                
        for(auto it: pref) cout<<it<<" ";
        cout<<endl;
        
        vector<bool> ans;
        for(auto it: queries){
            int st = it[0], ed = it[1], left,right;
            if(st == ed) ans.push_back(true);
            else{
                if(st > 0) left = pref[st-1];
                else left = 0;
                
                if(ed > 0) right = pref[ed-1];
                else right = 0;
                
                int diff = abs(right-left);
                if(diff > 0) ans.push_back(false);
                else ans.push_back(true);
            }
        }
        
        return ans;
    }
};