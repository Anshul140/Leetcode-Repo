class Solution {
public:
    string longestPalindrome(string s) { 
        int n = s.size();
        int start = 0, max_len = 1;

        for(int i = 0; i<n; i++) {
            // odd sized substring
            int left = i-1, right = i+1;
            while(left >= 0 and right < n and s[left] == s[right]) {
                if(right - left + 1 > max_len) {
                   max_len = right - left + 1;
                   start = left;
                }

                left--;
                right++;
            }

            // even sized
            left = i-1, right = i;
            while(left >= 0 and right < n and s[left] == s[right]) {
                if(right - left + 1 > max_len) {
                   max_len = right - left + 1;
                   start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, max_len);
    }
};