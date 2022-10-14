//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        vector<long long> temp;
        if(n == 1)
           return;
        
        int i = 0, j = 0;
        while(j < n) {
            temp.push_back(arr[j]);
            if(j - i + 1 == k) {
                reverse(temp.begin(), temp.end());
                int st = 0;
                for(int l = i; l<=j; l++) {
                    arr[l] = temp[st++];
                }
                temp.clear();
                i = j+1;
            }
            j++;
        }
        if(temp.size() != 0) {
            // cout<<temp.size()<<" sz "<<endl;
            reverse(temp.begin(), temp.end());
            int st = 0;
            for(int l = i; l<j; l++) {
                arr[l] = temp[st++];
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends