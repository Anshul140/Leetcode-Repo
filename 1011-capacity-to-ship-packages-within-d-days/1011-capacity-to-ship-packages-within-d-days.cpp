class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 1, hi = 1e9, mid, n = weights.size();
        // cout<<endl<<endl<<endl;
        int ans;
        while(lo <= hi) {
            mid = (lo + hi) >> 1;
            long cdays = 1, cw = 0, f = 1;
            for(int i = 0; i<n; i++) {
                if(weights[i] > mid) {
                    f = 0;
                    break;
                }
                cw += weights[i];
                if(cw > mid) {
                    cdays++;
                    cw = weights[i];
                }
            }
            
            if(cdays > days) f = 0;
            
            if(f) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        
        return ans;
    }
};