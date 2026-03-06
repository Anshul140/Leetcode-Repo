class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0, n = s.size();
        while(i < n and s[i] == '1') i++;

        for( ;i<n; i++) {
            if(s[i] == '1') return false;
        }

        return true;
    }
};