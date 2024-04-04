class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, ctr = 0;
        for(char ch: s) {
            if(ch == '(') {
                ctr++;
                ans = max(ans, ctr);
            } else if(ch == ')'){
                ctr--;
            }
        }
        
        return ans;
    }
};