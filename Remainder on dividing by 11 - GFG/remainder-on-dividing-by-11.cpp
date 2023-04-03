//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
        int s1 = 0, s2 = 0;
        for(int i = 0; i<x.size(); i++) {
            if(i & 1) {
                s1 += x[i] - '0';
            } else {
                s2 += x[i] - '0';
            }
        }
        
        // cout<<"s1: "<<s1<<" s2: "<<s2<<endl;
        int ans = (s1-s2)%11;
        return ans < 0 ? ans+11: ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends