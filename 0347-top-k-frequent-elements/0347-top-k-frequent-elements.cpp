class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int el: nums) mp[el]++;
        
        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }
        
        while(pq.size() > 0) {
            auto t = pq.top();
            ans.push_back(t.second);
            pq.pop();
        }
        
        return ans;
    }
};