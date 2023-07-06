class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int ans = Integer.MAX_VALUE;
        int n = nums.length;
        int i = 0, j = 0, sum = 0;
        while(j < n) {
            sum += nums[j];
            if(sum >= target) {
                //System.out.println("i: "+i+" j: "+j);
                
                while(sum >= target) {
                    ans = Math.min(ans, j - i + 1);
                    sum -= nums[i];
                    i++;
                }
            }
            j++;
        }
        return ans == Integer.MAX_VALUE? 0: ans;
    }
}