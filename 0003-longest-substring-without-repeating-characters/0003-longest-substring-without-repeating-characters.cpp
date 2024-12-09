class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int ans = 1;
        int i = 0, j = 0, n = s.size();
        if(!n) return 0;

        while(j < n){
            mp[s[j]]++;
            if(mp.size() == (j - i + 1)){
                // no repeating characters
                int cans = mp.size();
                ans = max(ans, cans);
            } else {
                // repeating characters present, hence map size less than window size
                while(mp.size() < (j - i + 1)){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                int cans = mp.size();
                ans = max(ans, cans);
            }
            j++;
        }

        return ans;
    }
};