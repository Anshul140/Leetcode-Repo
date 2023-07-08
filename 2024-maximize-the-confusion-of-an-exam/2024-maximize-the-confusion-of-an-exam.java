/*
FFFTTFFFF
k = 1

*/

class Solution {
    public int calculate(String str, int k, char ch) {
        int i = 0, j = 0, ans = 1, ct = 0, len = str.length();
        int ws = 0;
        
        while(j < len) {
            if(str.charAt(j) == ch) ws++;
            
            if(ws <= k) {
                ans = Math.max(ans, j - i + 1);
            } else {
                while(ws > k) {
                    if(str.charAt(i) == ch) ws--;
                    i++;
                }
            }
            j++;
        }
        
        return ans;
    }
    public int maxConsecutiveAnswers(String str, int k) {
        // convert T -> F
        int ans1 = calculate(str, k, 'T');
        
        // convert F -> T
        int ans2 = calculate(str, k, 'F');
        
        return Math.max(ans1, ans2);
    }
}
/*

System.out.println("i: "+i+" j: "+j);

TFTFTFTFTFTF 2

TTFFFTTFFTTT

2 3 2 2 3 

2 3 3 3 3 3 3
k = 6

T T T T F F F F T T T F F F
K = 6


*/