class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = -1;
        
        while(l < r) {
            int h = min(height[l], height[r]);
            int cans = h * (r-l);
            ans = max(ans, cans);
            
            if(height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return ans;
    }
};