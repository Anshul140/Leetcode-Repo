class Solution {
public:
    static bool compare(const vector<int>& v1,const vector<int>& v2) {
        if(v1[1] < v2[1]) return true;

        if(v1[1] == v2[1]) {
            if(v1[1] - v1[0] <= v2[1] - v2[0]) return true;
        }

        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return 0;

        sort(intervals.begin(), intervals.end(), compare);
        
        int ans = 0;

        int first = intervals[0][1];

        for(int i = 1;i<n;i++){
            if(intervals[i][0] >= first){
                first = intervals[i][1];
            }else{
                ans++;
            }
        }

        return ans;
    }
};