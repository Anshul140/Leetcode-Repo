class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        while(s.size() > 0 and s.back() == ' ') s.pop_back();
        
        int f = 0;
        while(s[f] == ' ') f++;
        
        int f1 = 0;
        for(int i = f; i<s.size(); i++) {
            if(s[i] != ' ') {
                temp.push_back(s[i]);
                f1 = 0;
            }
            else if(f1 == 1)
                continue;
            else {
                f1 = 1;
                temp.push_back(s[i]);
            }
        }
        
        vector<string> vs;
        string curr = "";
        // cout<<"-"<<temp<<"-"<<endl;
        
        for(int i = 0; i<temp.size(); i++) {
            if(temp[i] != ' ') curr += temp[i];
            else {
                vs.push_back(curr);
                curr = "";
            }
        }
        
        vs.push_back(curr);
        reverse(vs.begin(), vs.end());
        string ans = "";
        for(int i = 0; i<vs.size(); i++) {
            ans += vs[i];
            ans += ' ';
        }
        
        ans.pop_back();
        return ans;
    }
};