//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        map<char, int> mp;
        set<int> ids;
        
        int n = S.size(), f = 0;
        for(int i = 0; i<n; i++) ids.insert(i);
        
        for(auto ch: S) mp[ch]++;
        
        while(mp.size() != ids.size()) {
            if(f == 0) {
                int idx = -1;
                for(auto it = ids.begin(); it != ids.end(); it++) {
                    if(mp[S[*it]] > 1) {
                        mp[S[*it]]--;
                        idx = *it;
                        break;
                    }
                } 
                ids.erase(idx);
                f = 1;
            }
            else {
                int idx = -1;
                for(auto it = ids.rbegin(); it != ids.rend(); it++) {
                    if(mp[S[*it]] > 1) {
                        mp[S[*it]]--;
                        idx = *it;
                        break;
                    }
                }
                ids.erase(idx);
                f = 0;
            }
        }
        
        string ans = "";
        for(auto it: ids) ans.push_back(S[it]);
        
        if(f == 1) reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends