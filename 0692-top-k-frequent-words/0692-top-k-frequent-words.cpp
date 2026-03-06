class Solution {
public:
    struct cmp {
        bool operator()(pair<int,string> a, pair<int,string> b) {
            if(a.first == b.first) 
                return a.second < b.second;

            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;

        for(auto it: words) mp[it]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for(auto it: mp) {
            pq.push({it.second, it.first});
        }

        while(pq.size() > k and !pq.empty()) pq.pop();

        vector<string> ans(k);
        int itr = k-1;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ans[itr] = it.second;
            itr--;
        }

        return ans;
    }
};