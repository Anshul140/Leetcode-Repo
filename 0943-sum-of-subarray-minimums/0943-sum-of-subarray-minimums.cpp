class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n), pse(n);
        long long int mod = 1e9+7, ans = 0;
        stack<int> st;
        for(int i = 0; i<n; i++){
            if(st.empty()) pse[i] = -1;
            else {
                while(!st.empty() and nums[st.top()] > nums[i]) 
                    st.pop();
                if(!st.empty()) pse[i] = st.top();
                else pse[i] = -1;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i>=0; i--){
            if(st.empty()) nse[i] = n;
            else {
                while(!st.empty() and nums[st.top()] >= nums[i]) 
                    st.pop();
                if(!st.empty()) nse[i] = st.top();
                else nse[i] = n;
            }
            st.push(i);
        }

        for(int i = 0; i<n; i++){
            // cout<<"ith el: "<<nums[i]<<" pse: "<<pse[i]<<" nse: "<<nse[i]<<endl;
            long long diff = (i - pse[i])*(nse[i] - i);
            long long el = nums[i];
            long long sum = ((diff%mod)*(el%mod))%mod;
            ans += sum%mod;
        }

        return ans%mod;
    }
};