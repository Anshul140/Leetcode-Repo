class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;

        int n = words.size();
        vector<int> pref(n+1);

        for(int i = 0; i<n; i++){
            int sz = words[i].size();
            int add = isVowel(words[i][0]) and isVowel(words[i][sz-1]);  
            pref[i+1] = add + pref[i];
        }

        // cout<<"debug.... prefix sum"<<endl;
        // for(auto it: pref) cout<<it<<"  ";
        // cout<<endl;

        for(auto it: queries){
            int l = it[0], r = it[1];
            ans.push_back(pref[r+1] - pref[l]);
        }

        return ans;
    }
};