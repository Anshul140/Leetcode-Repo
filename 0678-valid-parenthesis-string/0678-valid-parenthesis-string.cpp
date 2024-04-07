class Solution {
public:
    bool checkValidString(string s) {
        deque<pair<char, int>> qc;
        stack<pair<char, int>> st;
        int n = s.size();
        
        for(int i = 0; i<n; i++) {
            if(st.size() == 0) {
                if(s[i] == '(') st.push({s[i], i});
                else if(s[i] == ')') {
                    if(qc.size() == 0) return false;
                    else {
                        qc.pop_back();
                    }
                } else {
                    qc.push_back({s[i], i});
                }
            } else {
                if(s[i] == ')') {
                    st.pop();
                } else if(s[i] == '(') {
                    st.push({s[i], i});
                } else {
                    qc.push_back({s[i], i});
                }
            }
        }
        
        while(st.size()) {
            if(qc.size()) {
                // stack top
                auto it1 = st.top();
                int idx1 = it1.second; 
                
                // queue last
                auto it2 = qc.back();
                int idx2 = it2.second;
                
                if(idx2 > idx1) {
                    st.pop();
                    qc.pop_back();
                } else {
                    return false;
                }
            }else {
                return false;
            }
        }
        
        return true;
    }
};