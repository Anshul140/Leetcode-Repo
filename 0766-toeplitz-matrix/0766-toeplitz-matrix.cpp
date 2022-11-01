class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        
        for(int col = 0; col<c; col++) {
            int i = 0, j = col;
            int x = mat[i][j];
            i++;
            j++;
            while(i < r and j < c) {
                if(mat[i][j] != x)
                    return false;
                i++;
                j++;
            }
        }
        
        for(int row = 0; row<r; row++) {
            int i = row, j = 0;
            int x = mat[i][j];
            i++, j++;
            
            while(i < r and j < c) {
                if(mat[i][j] != x)
                    return false;
                i++;
                j++;
            }
        }
        
        return true;
    }
};