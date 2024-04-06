class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        if(n < 2) return s;
        
        stack<char> st;
        for(int i = 0; i<n; i++){
            if(st.size() == 0) st.push(s[i]);
            else {
                if(abs(st.top() - s[i]) == 32) st.pop();
                else st.push(s[i]);
            }
        }
        
        string ans = "";
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
  ch1  ch2
u 0
l 0
*/