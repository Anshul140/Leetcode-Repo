class Solution {
public:
    int n;
    unordered_map<string, int> dp;
    
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];  // Compare based on the second value in each inner vector
    }
    
    // checks if x and y lie in between a and b
    bool isOverlap(int &a, int &b, int &x, int &y) {
        if(x > b and y > b) return false;
        if(x < a and y < a) return false;
        
        return true;
    }
    
    int solve(int cidx, int pidx, int cnt, vector<vector<int>>& events) {
        if(cidx >= n or cnt == 0) {
            return 0;
        }
        
        // Create a unique key for the current state
        string key = to_string(cidx) + "|" + to_string(pidx) + "|" + to_string(cnt);

        // Check if the result for the current state is already computed
        if (dp.count(key)) {
            return dp[key];
        }

        int take = 0, notTake = 0;
        if(pidx == -1) {
            take = events[cidx][2] + solve(cidx+1, cidx, cnt-1, events);
            notTake = solve(cidx+1, pidx, cnt, events);
        } else {
            notTake = solve(cidx+1, pidx, cnt, events);
            int pStart = events[pidx][0], pEnd = events[pidx][1];
            int cStart = events[cidx][0], cEnd = events[cidx][1];
            
            if(!isOverlap(pStart, pEnd, cStart, cEnd)) {
                take = events[cidx][2] + solve(cidx+1, cidx, cnt-1, events);
            }
        }
        
        return dp[key] = max(take, notTake);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end(), compare);
        dp.clear();
        return solve(0, -1, k, events);
    }
};
