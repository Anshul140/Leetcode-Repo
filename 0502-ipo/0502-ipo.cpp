class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if(a.first == b.first) return a.second > b.second;

            return a.first < b.first;
        }
    };

    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n = p.size();
        vector<pair<int, int>> vp;

        for(int i = 0; i<n; i++) {
            vp.push_back({c[i], p[i]});
        }

        sort(vp.begin(), vp.end());

        int ans = w;
        priority_queue<int> pq;

        int j = 0;
        for(int i = 0; i<k; i++) {
            while(j < n and vp[j].first <= ans) {
                pq.push(vp[j].second);
                j++;
            }

            if(pq.size() == 0) break;
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};