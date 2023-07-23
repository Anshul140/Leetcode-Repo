class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        stack<long long> st;
        int n = nums.size();
        
        for(int i = n-1; i>=0; i--) {
            if(st.size() == 0) st.push(nums[i]);
            else {
                if(st.top() >= nums[i]) {
                    long long top = st.top();
                    st.pop();
                    st.push(top + nums[i]);
                } else {
                    st.pop();
                    st.push(nums[i]);
                }
            }
        }
        
        return st.top();
    }
};
/*

2 3 7 9 3


*/