class Solution {
public:
    vector<int> arr;
    vector<bool> vis;
    set<vector<int>> ps;
    int n;

    void generatePermutations(vector<int>& cur) {
        if(cur.size() == arr.size()) {
            ps.insert(cur);
            return;
        }

        for(int i = 0; i<n; i++) {
            if(vis[i]) continue;
            vis[i] = true;
            cur.push_back(arr[i]);
            generatePermutations(cur);
            cur.pop_back();
            vis[i] = false;
        }
    }

    bool isValid(vector<int>& p) {
        vector<bool> diag1(2*n-1), diag2(2*n-1);

        bool valid = true;
        for(int i = 0; i<n; i++) {
            int j = p[i];
            if(diag1[i + j]) {
                valid = false;
                break;
            }

            diag1[i + j] = true;
        }

        for(int i = 0; i<n; i++) {
            int j = p[i];
            if(diag2[i - j + n - 1]) {
                valid = false;
                break;
            }

            diag2[i - j + n - 1] = true;
        }

        return valid;
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        arr.resize(n);
        vis.resize(n);
        vector<int> temp;
        vector<vector<string>> ans;

        for(int i = 0; i<n; i++) {
            arr[i] = i;
        }

        generatePermutations(temp);

        for(auto p: ps) {
            if(isValid(p)){
                vector<string> cans(n, string(n, '.'));
                for(int i = 0; i<n; i++) {
                    int j = p[i];
                    cans[i][j] = 'Q';
                }
                ans.push_back(cans);
            }
        }

        return ans;
    }
};