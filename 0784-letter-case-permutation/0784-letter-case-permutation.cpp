class Solution {
public:
    set<string> ans;

    void dfs(int i, string& s) {
        if(i == s.size()) {
            ans.insert(s);
            return;
        }

        if(!isalpha(s[i])) dfs(i+1, s);
        
        dfs(i+1, s);

        char cur = s[i];
        if(isupper(cur)) cur = (char)tolower(cur);
        else cur = (char)toupper(cur);

        // temp[i] = cur;
        s[i] = cur;
        dfs(i+1, s);
    }

    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        int a = 0;
        for(char ch: s) {
            if(isalpha(ch)) a++;
        }

        int tot = a*a;
        dfs(0, s);

        vector<string> res;
        for(auto it: ans) {
            cout<<it<<"   ";
            res.push_back(it);
        }
        cout<<endl;

        
        return res;
    }
};