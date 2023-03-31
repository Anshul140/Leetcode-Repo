//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &arr,int n)
        {
            // Code here
            multiset<int, greater<int>> ms;
            
            ms.insert(arr[0]);
            int start = 0, end = 0;
            for(int i = 1; i<n; i++) {
                if(arr[i] % 2 == arr[i-1]% 2) {
                    ms.insert(arr[i]);
                    end = i;
                } else {
                    for(int j = start; j<=end; j++) {
                        arr[j] = *ms.begin();
                        ms.erase(ms.begin());
                    }
                    start = i;
                    end = i;
                    // end = i+1;
                    ms.insert(arr[i]);
                }
            }
            
            for(int j = start; j<=end; j++) {
                arr[j] = *ms.begin();
                ms.erase(ms.begin());
            }
            return arr;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends