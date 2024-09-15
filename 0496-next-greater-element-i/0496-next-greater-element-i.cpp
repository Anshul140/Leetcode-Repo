class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        int n = nums2.size();
        vector<int> ans, ngr(n);

        for(int i = 0; i<n; i++) mp[nums2[i]] = i;

        stack<int> st;
        for(int i = n-1; i>=0; i--){
            if(st.empty()) {
                ngr[i] = -1;
            } else {
                while(!st.empty() and st.top() < nums2[i]){
                    st.pop();
                }
                if(!st.empty()) ngr[i] = st.top();
                else ngr[i] = -1;
            }
            st.push(nums2[i]);
        }

        for(int el: nums1){
            int cans = ngr[mp[el]];
            // cout<<"el: "<<el<<" i: "<<mp[el]<<" ngr: "<<cans<<endl;
            ans.push_back(cans);
        }

        return ans;
    }
};