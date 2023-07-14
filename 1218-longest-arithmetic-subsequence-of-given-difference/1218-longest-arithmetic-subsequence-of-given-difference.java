class Solution {
    public int longestSubsequence(int[] arr, int diff) {
        HashMap<Integer, Integer> dp = new HashMap<>();
        int ans = 1;
    
        for(int el: arr) {
            if(dp.containsKey(el - diff)) {
                int prev = dp.get(el - diff);
                ans = Math.max(ans, 1+prev);
                dp.put(el, prev+1);
            } else {
                dp.put(el, 1);
            }
        }
        
        return ans;
    }
}