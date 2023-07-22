class Solution {
public:
    unordered_map<string, double> mp;
    
    int dir[8][2] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};
    int r, c;
    
    bool isValid(int i, int j) {
        return (i >= 0 and i < r and j >= 0 and j < c);
    }
    
    double find(int n, int k, int row, int col) {
        if(!isValid(row, col)) return 0;
        
        // cout<<"k: "<<k<<endl;
        
        if(k == 0) return 1;
        
        // if(dp[k][row][col] != -1) return dp[k][row][col];
        string cur = to_string(k) + "a" + to_string(row) + "s" + to_string(col);
        if(mp.count(cur)) return mp[cur];
        
        double prob = 0.0;
        
        for(int i = 0; i<8; i++) {
            prob += find(n, k-1, row + dir[i][0], col + dir[i][1])/(8.0);
        }
        
        // cout<<"prob: "<<prob<<endl;
        // return dp[k][row][col] = prob;
        
        return mp[cur] = prob;
    }
    
    double knightProbability(int n, int k, int row, int col) {
        mp.clear();
        r = c = n;
        
        return find(n, k, row, col);
    }
};