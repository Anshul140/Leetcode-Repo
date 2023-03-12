//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        vector<int> ans;
        int row = 0, mxcnt = 0;
        
        for(int i = 0; i<N; i++) {
            int sum = 0;
            for(int j = 0; j<N; j++) {
                sum += mat[i][j];
            }
            if(sum > mxcnt) {
                mxcnt = sum;
                row = i;
            }
        }
        
        ans.push_back(row);
        ans.push_back(mxcnt);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends