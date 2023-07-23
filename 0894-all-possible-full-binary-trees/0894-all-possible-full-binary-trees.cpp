/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, vector<TreeNode*>> dp;
    
    vector<TreeNode*> dfs(int n) {
        vector<TreeNode*> res;
        if(n == 0) 
            return res;
        if(n == 1) {
            res.push_back(new TreeNode());
            return res;
        }
        
        if(dp.count(n)) return dp[n];
        
        for(int l = 0; l<n; l++) {
            int r = n-1-l;
            vector<TreeNode*> left = dfs(l);
            vector<TreeNode*> right = dfs(r);
            
            for(auto l: left) {
                for(auto r: right) {
                    res.push_back(new TreeNode(0, l, r));
                }
            }
        }
        
        return dp[n] = res;    
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        dp.clear();
        if(n == 2) return res;
        return dfs(n);
    }
};