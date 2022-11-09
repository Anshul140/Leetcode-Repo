//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here   
        long long int p = 1, z = 0;
        vector<long long int> ans;
        for(long long int el: nums) {
            p *= el;
            if(el == 0)
               z++;
        }
        
        if(z == 0) {
            for(long long int el: nums) {
                ans.push_back(p/el);
            }
        }
        else if(z == 1) {
            p = 1;
            for(long long int el: nums) {
                if(el == 0)
                   continue;
                p *= el;
            }
            for(long long int el: nums) {
                if(el != 0) ans.push_back(0);
                else ans.push_back(p);
            }
        }
        else {
            for(int i = 0; i<n; i++) ans.push_back(0);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends