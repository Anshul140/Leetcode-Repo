class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++) {
                set<int> s1, s2;
                int id = i-1, jd = j-1;
                while(id >= 0 and jd >= 0){
                    s1.insert(grid[id][jd]);
                    id--;
                    jd--;
                }
                
                id =i+1, jd =j+1;
                while(id < r and jd < c){
                    s2.insert(grid[id][jd]);
                    id++;
                    jd++;
                }
                
                int sz1 = s1.size(), sz2 = s2.size();
                ans[i][j] = abs(sz1 - sz2);
            }
        }
        
        return ans;
    }
};