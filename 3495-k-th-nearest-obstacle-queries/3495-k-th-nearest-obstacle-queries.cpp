class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& q, int k) {
        vector<int> ans;
        priority_queue<int> pq;

        for(auto it: q){
            pq.push(abs(it[0]) + abs(it[1]));
            if(pq.size() < k) ans.push_back(-1);
            else if(pq.size() >= k){
                if(pq.size() > k)
                    pq.pop();

                ans.push_back(pq.top());
            }
        }

        return ans;
    }
};

// [10,10,3,3,3]