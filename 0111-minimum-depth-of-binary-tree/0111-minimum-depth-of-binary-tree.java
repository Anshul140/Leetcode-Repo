/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    Set<Integer> set = new HashSet<>();
    int depth = 0;
    int ans = Integer.MAX_VALUE;
    
    public void dfs(TreeNode root) {
        if(root == null) return;
        depth++;
        
        if(root.left == null && root.right == null) {
            ans = Math.min(ans, depth);
            depth--;
            return;
        }
        
        if(root.left != null) dfs(root.left);
        if(root.right != null) dfs(root.right);
        
        depth--;     
    }
    
    public int minDepth(TreeNode root) {
        dfs(root);
        return ans == Integer.MAX_VALUE? 0: ans;
    }
}