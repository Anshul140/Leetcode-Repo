class Solution {
    int ans = Integer.MAX_VALUE;
    public void solve(int[] cookies, int k, int[] arr, int ind) {
        if(ind == cookies.length) {
            int curr = 0;
            for(int el: arr) curr = Math.max(curr, el);
            ans = Math.min(ans, curr);
            return;
        }
        
        for(int i = 0; i<k; i++) {
            arr[i] += cookies[ind];
            solve(cookies, k, arr, ind+1);
            arr[i] -= cookies[ind];
        }
    }
    
    public int distributeCookies(int[] cookies, int k) {
        solve(cookies, k, new int[k], 0);
        return ans;
    }
}

/*
1 1 2 2 2 3 4 6

*/