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
    vector<int> g[100005];
    
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        
        if(root->left) {
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
        }
        
        if(root->right) {
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
        }
        
        dfs(root->left);
        dfs(root->right);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);

        queue<int> q;
        set<int> vis;
        
        int ans = -1;
        q.push(start); 
        vis.insert(start);
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                
                for(int el: g[it]) {
                    if(!vis.count(el)) {
                        vis.insert(el);
                        q.push(el);
                    }
                }
            }
            ans++;
        }
        
        return ans;
    }
};