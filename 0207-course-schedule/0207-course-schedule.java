class Solution {
    boolean[] dvis = new boolean[2005];
    boolean[] vis = new boolean[2005];
    List<Integer>[] g = new ArrayList[2005];
    
    Solution() {
        for(int i=0;i<2005;i++) {
            dvis[i] = false;
            vis[i] = false;
            g[i] = new ArrayList<Integer>();
        }
    }
    
    // checks if any cycle is present or not
    public boolean dfs(int v) {
        
        dvis[v] = true;
        vis[v] = true;
        
        for(int el: g[v]) {
            if(!vis[el]){
                if(dfs(el)) return true;
            }else {
                if(dvis[el]) return true;
            }
        }
        
        dvis[v] = false;
        return false;
    }
    
    public boolean canFinish(int n, int[][] graph) {
        int r = graph.length;
        
        for(int i=0;i<r;i++) {
            g[graph[i][0]].add(graph[i][1]);
        }
        
        for(int i = 0;i<n;i++){
            if(!vis[i]) {
                if(dfs(i)) return false;
            }
        }
        
        return true;
    }
}