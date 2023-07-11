/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    List<Integer>[] g = new ArrayList[505];
    
    public void init() {
        for (int i = 0; i < 505; i++) {
            g[i] = new ArrayList<Integer>();
        }
    }
    
    public void preOrder(TreeNode root) {
        if(root == null) return;
        
        if(root.left == null && root.right == null) return;
        
        if(root.left != null) {
            int x = root.val;
            int y = root.left.val;
            g[x].add(y);
            g[y].add(x);
        }
        
        if(root.right != null) {
            int x = root.val;
            int y = root.right.val;
            g[x].add(y);
            g[y].add(x);
        }
        
        preOrder(root.left);
        preOrder(root.right);
    }
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        init();
        preOrder(root);
        
        List<Integer> ans = new ArrayList<>();
        
        int n = g.length;
        Queue<Integer> queue = new LinkedList<>();
        boolean[] vis = new boolean[n+5];
        
        queue.offer(target.val);
        vis[target.val] = true;
        int depth = 0;
        
        while(queue.size() != 0) {
            
            int sz = queue.size();
            while(sz-- > 0) {
                int node = queue.poll();
                
                if(depth == k) {
                    ans.add(node);
                }
                
                for(int el: g[node]) {
                    if(!vis[el]) {
                        queue.offer(el);
                        vis[el] = true;
                    }
                }
            }
            depth++;
            if(depth > k) break;
        }
        
        return ans;
    }
}