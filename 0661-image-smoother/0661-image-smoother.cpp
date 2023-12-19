class Solution {
public:
    int dir[8][2] = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1},   // Right
        {-1, -1}, // Diagonal Up-Left
        {-1, 1},  // Diagonal Up-Right
        {1, -1},  // Diagonal Down-Left
        {1, 1}    // Diagonal Down-Right
    };
    
    int r;
    int c;
    
    bool isValid(int x, int y) {
        return (x >= 0 and y >= 0 and x < r and y < c);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        r = img.size(), c = img[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        
        
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                int sum = img[i][j], ctr = 1;
                for(int k = 0; k<8; k++) {
                    int xd = i+dir[k][0];
                    int yd = j+dir[k][1];
                    if(isValid(xd, yd)) {
                        sum += img[xd][yd];
                        ctr++;
                    }
                }
                ans[i][j] = sum/ctr;
            }
        }
        
        return ans;
    }
};