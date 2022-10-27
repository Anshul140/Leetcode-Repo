class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<pair<int, int>> vp1, vp2;
        int n = a.size(), ans = 0;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(a[i][j] == 1)
                    vp1.push_back({i, j});
                if(b[i][j] == 1)
                    vp2.push_back({i, j});
            }
        }
        
        map<pair<int, int>, int> mp;
        
        for(auto it1: vp1) {
            for(auto it2: vp2) {
                int x = it1.first-it2.first;
                int y = it1.second-it2.second;
                
                mp[{x, y}]++;
                ans = max(ans, mp[{x, y}]);
            }
        }
        
        return ans;
    }
};