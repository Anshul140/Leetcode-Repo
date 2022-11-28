class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> tot;
        unordered_map<int, int> mp;
        
        for(auto &it: matches) {
            mp[it[1]]++;
            tot.insert(it[0]);
            tot.insert(it[1]);
        }
        
        vector<int> w, l;
        for(auto &it: tot) {
            if(!mp.count(it)) {
                w.push_back(it);
            }
            else if(mp[it] == 1) {
                l.push_back(it);
            }
        }
        
        return {w,l};
    }
};