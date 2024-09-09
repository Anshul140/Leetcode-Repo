//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    vector<bool> vis, dvis;
    
    bool dfs(int v, vector<int> adj[]) {
        vis[v] = true;
        dvis[v] = true;
        
        for(int el: adj[v]){
            if(!vis[el] and dfs(el, adj))
                return true;
            else if(dvis[el])
                return true;
        }
        
        dvis[v] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vis.resize(V+5);
        dvis.resize(V+5);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends