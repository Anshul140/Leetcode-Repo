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
    bool findTarget(TreeNode* root, int k) {
        map<int, int> mp;
        queue<TreeNode*> q;

        // if(!root or !root->left or !root->right) return false;

        q.push(root);
        // mp[root->val]++;

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i<sz; i++) {
                auto it = q.front();
                q.pop();
                if(mp.count(k - it->val)) return true;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                mp[it->val]++;
            }
        }

        return false;
    }
};