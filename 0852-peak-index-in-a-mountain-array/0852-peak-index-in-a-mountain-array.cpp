class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 1, hi = n-2;
        
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]) {
                return mid;
            } else if(arr[mid-1] < arr[mid] and arr[mid] < arr[mid+1]) {
                lo = mid+1;
            } else if(arr[mid-1] > arr[mid] and arr[mid] > arr[mid+1]) {
                hi = mid-1;
            }
        }
        
        return -1;
    }
};