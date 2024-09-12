//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool comp(const pair<int, int>& p1, const pair<int, int>& p2){
        if(p1.second != p2.second)
            return p1.second > p2.second;
        else
            return p1.first < p2.first;
    }
    
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int, int> mp;
        for(int el: arr) mp[el]++;
        
        vector<pair<int, int>> vp;
        for(auto it: mp) vp.push_back({it.first, it.second});
        
        sort(vp.begin(), vp.end(), comp);
        vector<int> ans;
        
        for(auto it: vp){
            int sz = it.second;
            for(int i = 0; i<sz; i++) ans.push_back(it.first);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends