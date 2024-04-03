class Solution {
public:
    int r;
    int c;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isValid(int i, int j) {
        return (i >= 0 and i < r and j >= 0 and j < c);
    }
    
    bool dfs(int x, int y, int ind, vector<vector<char>>& mat, string& word) {
        if(ind == word.size()) return true;
        if(!isValid(x, y)) return false;
        
        char ch = word[ind];
        
        if(mat[x][y] != ch) return false;
        
        char temp = mat[x][y];
        mat[x][y] = '*';
        
        for(int i = 0; i<4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            if(dfs(nx, ny, ind+1, mat, word)) return true;
        }
        
        mat[x][y] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& mat, string word) {
        r = mat.size();
        c = mat[0].size();
        
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(word[0] == mat[i][j] and dfs(i, j, 0, mat, word)) return true;
            }
        }
        
        return false;
    }
};

