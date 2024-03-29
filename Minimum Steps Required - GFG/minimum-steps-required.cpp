//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int ct1 = 0, ct2 = 0, n = str.size();
    
    if(str[0] == 'a') ct1++;
    else ct2++;
    
    for(int i = 1; i<n; i++) {
        if(str[i] != str[i-1]) {
            if(str[i] == 'a') ct1++;
            else ct2++;
        } 
    }
    
    return min(ct1, ct2)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends