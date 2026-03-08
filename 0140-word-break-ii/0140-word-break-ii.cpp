class Solution {
public:
    set<string> words;
    string s;
    vector<string> temp;
    vector<string> ans;
    int maxLen = 0;
    int n;
    map<int, vector<string>> dp;

    vector<string> solve(int i) {
        if(dp.count(i)) return dp[i];

        vector<string> res;
        if(i == n) {
            res.push_back("");
            return dp[i] = res;
        }

        for(int j = i+1; j <= n; j++) {
            string word = s.substr(i, j-i);

            cout<<"word: "<<word<<endl;
            if(words.count(word)) {
                // cout<<"found in set"<<endl;
                vector<string> rest = solve(j);
                cout<<"word: "<<word<<" rest size: "<<rest.size()<<endl<<endl;
                for(auto str: rest) {
                    if(str == "") res.push_back(word);
                    else res.push_back(word + " " + str);
                }
            }
        }

        return dp[i] = res;
    }

    vector<string> wordBreak(string S, vector<string>& wd) {
        s = S;
        n = s.size();
        for(auto it: wd) {
            words.insert(it);
            int len = it.size();
            maxLen = max(maxLen, len);
        }
        
        vector<string> temp = solve(0);

        // cout<<"temp size: "<<temp.size()<<endl;
        // for(auto v: temp) {
        //     cout<<v<<"  ";
        //     cout<<endl;
        // }

        return temp;
    }
};