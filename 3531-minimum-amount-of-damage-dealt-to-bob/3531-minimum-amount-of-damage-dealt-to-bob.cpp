class Solution {
public:
    long long cnt(int a, int b){
        if(a % b == 0) return a/b;

        return (a/b)+1;
    }

    static bool customComparator(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        double d1 = a.first.second, t1 = a.second;
        double d2 = b.first.second, t2 = b.second;

        if(d1/t1 != d2/t2) return d1/t1 > d2/t2;

        return t1 < t2;
    }

    long long minDamage(int p, vector<int>& d, vector<int>& h) {
        long long tot = 0;
        int n = d.size();
        vector<pair<pair<int, int>, int>> vp;

        for(int i = 0; i<n; i++) {
            tot += d[i];
            vp.push_back({{h[i], d[i]}, cnt(h[i], p)});
        }
        sort(vp.begin(), vp.end(), customComparator);

        long long ans = 0;
        for(auto it: vp){
            long long ctr = it.second;
            ans += ctr*tot;
            tot -= it.first.second;
        }

        return ans;
    }
};