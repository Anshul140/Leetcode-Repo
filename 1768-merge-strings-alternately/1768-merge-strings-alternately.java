class Solution {
    public String mergeAlternately(String word1, String word2) {
        String res = "";
    
        int s1 = word1.length();
        int s2 = word2.length();
        
        int i = 0, j = 0, k = 0, f = 0;
        while(i < s1+s2 && j < s1 && k < s2) {
            if(f == 0) {
                res += word1.charAt(j);
                i++;
                j++;
                f = 1;
            } else {
                res += word2.charAt(k);
                i++;
                k++;
                f = 0;
            }
        }
        
        //System.out.println("char array: "+str);
        
        while(j < s1) {
            res += word1.charAt(j);
            i++;
            j++;
        }
        while(k < s2) {
            res += word2.charAt(k);
            i++;
            k++;
        }
        return res;
    }
}