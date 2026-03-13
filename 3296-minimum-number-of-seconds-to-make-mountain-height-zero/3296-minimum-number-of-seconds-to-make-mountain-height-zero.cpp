class Solution {
public:
    long long find_max_terms_binary(long long t, long long x) {
        long long low = 0, high = 2e9; // Adjusted for 64-bit limits
        long long ans = 0;
        long long limit = t / x;

        while (low <= high) {
            long long mid = low + ((high - low) >> 1);
            
            // Use __int128 or careful multiplication to avoid overflow
            if (mid <= 0) { low = mid + 1; continue; }
            
            // Check if n*(n+1)/2 <= limit
            if (mid <= (2 * limit) / (mid + 1)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    bool isValid(vector<int>& nums, long long t, int mh) {
        long long tot = 0;
        // cout<<"mid: "<<t<<endl;
        for(auto x: nums) {
            long long cans = find_max_terms_binary(t, x);
            tot += cans;
            // cout<<"el: "<<x<<" cans: "<<cans<<endl;
            if(tot >= mh) {
                cout<<endl;
                return true;
            }
        }

        // cout<<"false"<<endl;
        return false;
    }

    long long minNumberOfSeconds(int mh, vector<int>& nums) {
        long long lo = 1, hi = 1LL * nums[0] * mh * (mh + 1) / 2;
        long long ans = LONG_MAX;
        sort(nums.begin(), nums.end());

        while(lo <= hi) {
            long long mid = lo + (hi - lo)/2;
            if(isValid(nums, mid, mh)) {
                ans = min(ans, mid);
                hi = mid-1;
                // cout<<"valid mid: "<<mid<<endl;
            } else {
                lo = mid+1;
                // cout<<"invalid mid: "<<lo<<endl;
            }
        }

        return ans;
    }
};