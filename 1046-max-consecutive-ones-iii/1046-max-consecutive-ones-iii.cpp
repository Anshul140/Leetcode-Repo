class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = k, i = 0, j = 0, n = nums.size();
        int z = 0;

        while(j < n){
            if(!nums[j]) z++;

            while(z > k){
                if(nums[i] == 0) z--;
                i++;
            }

            ans = max(ans, (j-i+1));
            j++;
        }

        return ans;
    }
};