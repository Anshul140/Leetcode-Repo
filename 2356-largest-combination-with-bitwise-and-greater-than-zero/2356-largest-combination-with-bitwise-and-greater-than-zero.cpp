class Solution {
public:
    int largestCombination(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, ctr = 0;
        vector<bitset<32>> vb;
        for(int i = 0; i<n; i++) {
            bitset<32> bs(arr[i]);
            // cout<<arr[i]<<":   "<<bs<<endl;
            vb.push_back(bs);
        }
        cout<<endl;
        // cout<<"vb size: "<<vb.size()<<endl<<endl;

        // cout<<"idx:    count"<<endl;
        for(int i = 0; i<32; i++) {
            for(int j = 0; j<n; j++) {
                ctr += vb[j].test(i);
            }
            // cout<<i<<": "<<ctr<<endl;
            ans = max(ans, ctr);
            ctr = 0;
        }

        return ans;
    }
};