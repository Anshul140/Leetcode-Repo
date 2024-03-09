class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int &el: nums) {
            pq.push(el);
        }
        
        int ct = k-1;
        while(ct){
            pq.pop();
            ct--;
        }
        
        return pq.top();
    }
};