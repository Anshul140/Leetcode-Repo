class Solution {
public:
    bool solve(int i, int j, long p1, long p2, vector<int>& nums, int f) {
        if(i > j) {
            return p1 >= p2;
        }
        
        if(f == 0) {
            return solve(i+1, j, p1+nums[i], p2, nums, 1) or solve(i, j-1, p1+nums[j], p2, nums, 1);
        } else {
            return solve(i+1, j, p1, p2+nums[i], nums, 0) && solve(i, j-1, p1, p2+nums[j], nums, 0);
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
       int n = nums.size();
       return solve(0, n-1, 0, 0, nums, 0);
       // return ans; 
    }
};

/*
1 5 2
p1: 1 2
p2: 5
*/