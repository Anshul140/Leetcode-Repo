class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        for(int i = 0; i<n-1; i++) {
            ans++;
            ans |= x;
        }
        return ans;
    }
};

/*
0
1
10
11
100
101
110
111
*/