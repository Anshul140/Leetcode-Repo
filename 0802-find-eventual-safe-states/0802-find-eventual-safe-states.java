class Solution {
    
    List<Integer>[] g = new ArrayList[10005];
    boolean[] vis = new boolean[10005];
    boolean[] dvis = new boolean[10005];   
    
    Solution() {
        for (int i = 0; i < 10005; i++) {
            g[i] = new ArrayList<Integer>();
            vis[i] = false;
            dvis[i] = false;
        }
    }
    
    //checks for cycle
    boolean dfs(int v) {
        vis[v] = true;
        dvis[v] = true;
        
        for(int el: g[v]) {
            if(!vis[el]) {
                if(dfs(el)) return true;
            } else {
                if(dvis[el] == true) return true;
            }
        }
        
        dvis[v] = false;
        return false;
    }
    
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> ans = new ArrayList<>();
        
        int r = graph.length;
        for(int i = 0; i<r; i++) {
            for(int el: graph[i]) {
                g[i].add(el);
            }
            //System.out.println("Size: "+g[i].size());
        }
        
        for(int i = 0; i<r; i++) {
            if(!dfs(i)) ans.add(i);
        }
        
        return ans;
    }
}