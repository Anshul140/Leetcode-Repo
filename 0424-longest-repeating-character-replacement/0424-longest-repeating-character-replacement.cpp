class Solution {
public:
    int maxFrequency(map<char, int>& mp){
        int ans = 0;
        for(auto &it: mp){
            ans = max(ans, it.second);
        }

        return ans;
    }

    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int mxf = 0, i = 0, j = 0, n = s.size(), ans = 1;

        while(j < n) {
            mp[s[j]]++;
            mxf = max(mxf, maxFrequency(mp));
            if((j-i+1)-mxf <= k){
                ans = max(ans, (j - i + 1));
            } else {
                while((j - i + 1) - mxf > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                    mxf = maxFrequency(mp);
                }
                ans = max(ans, (j - i + 1));
            }
            j++;
        }

        return ans;
    }
};