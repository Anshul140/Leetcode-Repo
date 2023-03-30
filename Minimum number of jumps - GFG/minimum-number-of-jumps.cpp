//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n == 1) return 0;
        
        if(arr[0] == 0) return -1;
        
        int last = 0, step = -1;
        vector<int> dp(n+5);
        
        dp[0] = 0;
        
        for(int i = 1; i<=n; i++) dp[i] = INT_MAX;
        
        for(int i = 0; i<n; i++) {
            int x = arr[i];
            
            if(last+x == i) return -1;
            
            for(int j = last+1; j<=min(i+x, n); j++) {
                dp[j] = min(dp[i]+1, dp[j]);
                last = max(last, j);
            }
            
            
            // for(int k = 0; k<n; k++) {
            //     cout<<dp[i]<<" ";
            // }
            // cout<<endl;
            if(last >= n-1)
               break;
        }
        
        return dp[n-1] == INT_MAX?-1: dp[n-1];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends