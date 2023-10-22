class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);

        // Calculate the minimum values to the left of each element
        for (int i = 1; i < n; i++) {
            left[i] = min(left[i - 1], nums[i - 1]);
        }

        // Calculate the minimum values to the right of each element
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i + 1]);
        }

        int ans = INT_MAX;

        // Check all possible 'j' indices
        for (int j = 1; j < n - 1; j++) {
            if (left[j] < nums[j] && right[j] < nums[j]) {
                ans = min(ans, left[j] + nums[j] + right[j]);
            }
        }

        return (ans != INT_MAX) ? ans : -1;
    }
};