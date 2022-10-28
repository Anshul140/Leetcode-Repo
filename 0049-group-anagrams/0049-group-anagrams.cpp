class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        map<string, vector<string>> mp;
        
        for(auto st: strs) {
            string temp = st;
            sort(temp.begin(), temp.end());
            
            mp[temp].push_back(st);
        }
        
        for(auto &it: mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};