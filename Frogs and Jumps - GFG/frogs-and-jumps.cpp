//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int l, int f[]) {
        // Code here
        set<int> leaves, frogs;
        for(int i = 1; i<=l; i++) leaves.insert(i);
        
        for(int i = 0; i<N; i++) frogs.insert(f[i]);
        
        sort(f, f+N);
        
        if(f[0] == 1) return 0;
        
        for(auto it: frogs) {
            int cur = it;
            while(cur <= l) {
                if(leaves.count(cur)) {
                    leaves.erase(cur);
                }
                cur += it;
            }
            
            if(leaves.size() == 0) return 0;
        }
        
        return leaves.size();
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends