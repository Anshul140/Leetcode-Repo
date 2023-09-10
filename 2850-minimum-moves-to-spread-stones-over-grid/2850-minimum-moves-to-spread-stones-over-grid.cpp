class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int t = 0;
        for(int i = 0; i<3; i++)
            for(int j = 0; j<3; j++)
                if(grid[i][j] == 0)
                    t++;
        if(t == 0) return 0;

        int ans = INT_MAX;
        for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                if(grid[i][j] == 0) {

                    for(int a = 0; a<3; a++) {
                        for(int b = 0; b<3; b++) {

                            int d = abs(i - a) + abs(j - b);

                            if(grid[a][b] > 1) {
                                grid[a][b]--;
                                grid[i][j]++;
                                ans = min(ans, d + minimumMoves(grid));
                                grid[a][b]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};