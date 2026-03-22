class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n));

        int col = n-1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                ans[j][col] = mat[i][j];
            }
            col--;
        }

        return ans;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        cout<<"actual matrix: "<<endl;
        for(int i = 0; i<mat.size(); i++) {
            for(int j = 0; j<mat.size(); j++) {
                cout<<mat[i][j]<<"  ";
            }
            cout<<endl;
        }

        cout<<"rotated matrix: "<<endl;
        for(int i = 0; i<4; i++) {
            vector<vector<int>> t = rotate(mat);
            for(int i = 0; i<mat.size(); i++) {
                for(int j = 0; j<mat.size(); j++) {
                    cout<<t[i][j]<<"  ";
                }
                cout<<endl;
            }
            cout<<endl;
            if(t == target) return true;
            swap(mat, t);
        }
        return false;
    }
};