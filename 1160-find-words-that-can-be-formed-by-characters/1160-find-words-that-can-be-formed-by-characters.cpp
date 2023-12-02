class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> mp;
        for(char ch: chars) mp[ch]++;
        
        int ans = 0;
        
        for(auto it: words) {
            map<char, int> mpd;
            int f = 0;
            for(char ch: it) {
                if(mp.count(ch)) {
                    mpd[ch]++;
                    if(mpd[ch] > mp[ch]) {
                        f=1;
                        break;
                    }
                } else {
                    f=1;
                    break;
                }
            }
            if(!f) ans += it.size();
        }
        
        return ans;
    }
};