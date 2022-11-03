class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        
        for(auto &it: words) mp[it]++;
        
        int ans = 0, eq = 0;
        for(auto it: mp) {
            string curr = it.first;
            reverse(curr.begin(), curr.end());
            // cout<<"it: "<<it.first<<"   cnt: "<<it.second<<endl;
            
            if(curr == it.first) {
                if(it.second & 1) {
                    // cout<<"eq-odlen...\n";
                    ans += 2*(it.second-1);
                    eq++;
                }
                else {
                    // cout<<"eq-evenlen...\n";
                    ans += 2*it.second;
                }
            }
            else if(mp.count(curr)) {
                // cout<<"neq-len...\n";
                int cnt1 = it.second;
                int cnt2 = mp[curr];
                int len = min(cnt1, cnt2);
                ans += 4*len;
                mp.erase(curr);
            }
            
        }
        
        if(eq > 0)
            ans += 2;
        return ans;
    }
};