/*
FFFTTFFFF
k = 1

*/

class Solution {
    public int calculate(String str, int k, char ch) {
        int i = 0, j = 0, ans = 1, ct = 0, len = str.length();
        int ws = 0;
        Queue<Character> q = new LinkedList<>();
        
        while(j < len) {
            q.offer(str.charAt(j));
            if(str.charAt(j) == ch) {
                ws++;
            }
            
            if(ws <= k) {
                ans = Math.max(ans, q.size());
            } else {
                while(ws > k) {
                    char c = q.poll();
                    if(c == ch) ws--;
                }
            }
            j++;
        }
        
        return ans;
    }
    public int maxConsecutiveAnswers(String str, int k) {
        // convert T -> F
        int ans1 = calculate(str, k, 'T');
        System.out.println("ans1: "+ans1);
        
        // convert F -> T
        int ans2 = calculate(str, k, 'F');
        System.out.println("ans2: "+ans2);
        
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