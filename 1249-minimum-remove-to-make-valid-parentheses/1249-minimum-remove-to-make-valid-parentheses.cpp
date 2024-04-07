class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        int n = s.size();
        
        set<int> idx;
        
        for(int i = 0; i<n; i++) {
            if(st.size() == 0) {
                if(s[i] == '(') st.push({s[i], i});
                else if(s[i] == ')') {
                    // cout<<"...debug 1: "<<i<<endl;
                    idx.insert(i);
                }
            }
            else {
                if(s[i] == ')') {
                    // cout<<"pop...."<<i<<"    ch: "<<s[i]<<endl;
                    st.pop();
                } else if(s[i] == '(') {
                    st.push({s[i], i});
                }
            }
        }
        
        while(st.size()) {
            auto it = st.top();
            // cout<<"...debug 2: "<<it.second<<endl;
            idx.insert(it.second);
            st.pop();
        }
        
        string ans = "";
        for(int i = 0; i<n; i++) {
            if(!idx.count(i)) ans.push_back(s[i]);
        }
        
        return ans;
    }
};