class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2) {
        return v1[0] <= v2[0];
    }
    
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int diff = 0;
        for(int i = 1; i<points.size(); i++) {
            // cout<<"x: "<<points[i][0]<<"  y: "<<points[i][1]<<endl;
            if(points[i][0]-points[i-1][0] > diff) diff = points[i][0]-points[i-1][0];
        }
        
        return diff;
    }
};