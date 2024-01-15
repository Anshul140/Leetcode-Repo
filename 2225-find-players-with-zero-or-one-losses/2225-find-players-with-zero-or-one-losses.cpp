class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> players;
        map<int, int> mp;
        for(auto &it: matches) {
            players.insert(it[0]);
            players.insert(it[1]);
            mp[it[1]]++;
        }
        
        vector<int> ans1, ans2;
        vector<vector<int>> ans;
        
        for(auto &it: players) {
            if(!mp.count(it)) {
                ans1.push_back(it);
            }
        }
        
        for(auto &it: mp) {
            if(it.second == 1) {
                ans2.push_back(it.first);
            }
        }
        
        //sort(ans1.begin(), ans1.end());
        //sort(ans2.begin(), ans2.end());
        
        ans.push_back(ans1);
        ans.push_back(ans2);
        
        return ans;
    }
};