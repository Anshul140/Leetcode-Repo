class Solution {
public:
    set<string> words;
    string s;
    vector<int> dp;

    bool solve(int i) {
        if(i >= s.size()) return true;

        if(dp[i] != -1) return dp[i];
        
        for(auto w: words) {
            int len = w.size();
            if(i + len - 1 >= s.size()) continue;

            if(s.substr(i, len) == w and solve(i+len))
                return dp[i] = 1;
        }

        return dp[i] = 0;
    }

    bool wordBreak(string S, vector<string>& wd) {
        s = S;
        for(auto it: wd) words.insert(it);
        dp.resize(305, -1);

        return solve(0);
    }
};