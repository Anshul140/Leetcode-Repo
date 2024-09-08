class Solution {
public:
    bool isValid(const vector<int>& start, int d, int diff) {
        int n = start.size();
        long long prev = start[0];  

        for (int i = 1; i < n; i++) {
            long long lb = prev + diff;  
            long long cur = start[i];
            if (lb > cur + d) {
                return false;  
            }
            prev = max(cur, lb);  
        }
        return true;
    }
    
    
    int solve(vector<int>& start, int d) {
        int n = start.size();
    
        sort(start.begin(), start.end());

        long long left = 0;
        long long right = d + start[n - 1];  

        long long best = 0;  

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (isValid(start, d, mid)) {
                best = mid;  
                left = mid + 1;  
            } else {
                right = mid - 1;  
            }
        }

        return best;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        return solve(start, d);
    }
};