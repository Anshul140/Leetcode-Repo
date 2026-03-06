class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        // int mn = INT_MAX, mx = -1;
        multiset<int> ws;

        while(j < n) {
            ws.insert(nums[j]);
            int mn = *ws.begin();
            int mx = *ws.rbegin();
            if(abs(mn-mx) <= limit) ans = max(ans, (j-i+1));
            else {
                while(ws.size() > 0 and abs(mn - mx) > limit) {
                    ws.erase(ws.find(nums[i]));
                    i++;
                    ans = max(ans, (j - i + 1));
                    mn = *ws.begin();
                    mx = *ws.rbegin();
                }
            }
            j++;
        }

        return ans;
    }
};