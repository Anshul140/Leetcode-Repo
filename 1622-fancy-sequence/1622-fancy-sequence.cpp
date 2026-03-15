class Fancy {
public:
    vector<long long> arr;
    const long long mod = 1e9+7;
    long long add, m;

    long long binExp(long long a, long long p) {
        long long res = 1;
        while(p > 0) {
            if(p&1) {
                res *= a;
                res %= mod;
            }
            a *= a;
            a %= mod;
            p >>= 1;
        }

        return res%mod;
    }

    Fancy() {
        m = 1;
        add = 0;
    }
    
    void append(int val) {
        long long t1 = (val - add + mod) % mod;
        long long t2 = binExp(m, mod-2);
        long long res = 1;
        res *= t1;
        res %= mod;

        res *= t2;
        res %= mod;

        arr.push_back(res);
    }
    
    void addAll(int inc) {
        add += inc;
        add %= mod;
    }
    
    void multAll(int mul) {
        m *= mul;
        m %= mod;

        add *= mul;
        add %= mod;
    }
    
    int getIndex(int idx) {
        int n = arr.size();

        if(idx >= n) return -1;

        long long ans = arr[idx];
        ans *= m;
        ans %= mod;

        ans += add;
        ans %= mod;

        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */