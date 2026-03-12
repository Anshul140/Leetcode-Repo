class Solution {
public:
    vector<vector<int>> ones, zeros;
    int k;
    int n;

    struct DSU{
        int n, c;
        vector<int> p, s;

        DSU(int N) {
            n = N;
            c = N;
            p.resize(n+1);
            s.resize(n+1);

            for(int i = 0; i<n; i++) {
                p[i] = i;
                s[i] = 1;
            }
        }

        int find(int x) {
            while(x != p[x]) x = p[x];
            return x;
        }

        bool same(int x, int y) {
            return find(x) == find(y);
        }

        void unite(int x, int y) {
            x = find(x);
            y = find(y);

            if(s[y] > s[x]) swap(x, y);

            s[x] += s[y];
            p[y] = x;
            c--;
        }
    };

    int maxStability(int N, vector<vector<int>>& edges, int K) {
        k = K;
        n = N;

        DSU dsu(n);
        int ans = INT_MAX;
        for(auto it: edges) {
            if(it[3]) {
                if(!dsu.same(it[0], it[1])) {
                    dsu.unite(it[0], it[1]);
                    ans = min(ans, it[2]);
                }
                else return -1;
            }
            else {
                zeros.push_back(it);
            }
        }

        // sort(ones.begin(), ones.end(), [](const vector<int>& a, const vector<int>& b) {
        //     return (a[2] > b[2]);
        // });

        sort(zeros.begin(), zeros.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[2] > b[2]);
        });

        vector<int> used;

        for(auto it: zeros) {
            if(!dsu.same(it[0], it[1])) {
                dsu.unite(it[0], it[1]);
                used.push_back(it[2]);
            }
        }

        int idx = used.size() - 1;
        while(k-- and idx >= 0) {
            ans = min(ans, 2*used[idx]);
            idx--;
        }

        if(dsu.c != 1) return -1;

        if(idx >= 0) {
            return min(ans, used[idx]);
        }

        return ans;
    }
};