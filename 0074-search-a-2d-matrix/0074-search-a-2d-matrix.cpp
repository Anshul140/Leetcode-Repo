class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int lo = 0, hi = r*c-1;
        
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int x = mid/c, y = mid%c;
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] > target) hi--;
            else lo++;
        }
        
        return false;
    }
};
/*
0,1,2,3,4,5,6,7,8,9,10,11

search = 3
r = 3, c = 4
lo = 0, hi = 11, mid = 5
x = (mid/c) = 1, y = (mid%c) = 1
matrix[x][y] > 2, hence, hi = mid-1 = 4

lo = 0, hi = 4, mid = 2
x = 0, y = 2
matrix[x][y] > 3, hence hi = 1

lo = 0, hi = 1, mid = 0
x = 0, y = 0
mid[x][y] < 3, hence lo = mid+1 = 1

lo = 1, hi = 1
x = 0, y = 1
mid[x][y] = 3, return true
*/