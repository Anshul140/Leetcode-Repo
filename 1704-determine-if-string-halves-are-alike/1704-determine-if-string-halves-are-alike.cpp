class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or
               ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U');
    }
    
    bool halvesAreAlike(string s) {
        int n = s.size();
        int ctr = 0;
        for(int i = 1; i<=n; i++) {
            if(i <= (n/2)) {
                if(isVowel(s[i-1])) ctr++;
            } else {
                if(isVowel(s[i-1])) ctr--;
            }
        }
        
        return ctr == 0;
    }
};