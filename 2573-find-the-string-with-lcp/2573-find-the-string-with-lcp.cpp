class Solution {
public:
    struct DSU {
        int n;
        vector<int> p, s;

        DSU(int N) {
            n = N;
            p.resize(n+1);
            s.resize(n+1);

            for(int i = 0; i<=n; i++) {
                p[i] = i;
                s[i] = 1;
            }
        }

        int find(int x) {
            if(p[x] == x) return x;
            return p[x] = find(p[x]);
        }

        void unite(int a, int b) {
            a = find(a), b = find(b);
            if(a != b) {
                if(s[a] < s[b]) swap(a, b);

                s[a] += s[b];
                p[b] = a;
            }
        }
    };
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        DSU dsu(n+1);

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(lcp[i][j] > 0) dsu.unite(i, j);
            }
        }

        string ans(n, '?');
        char ch = 'a';

        unordered_map<int, char> mp;

        for(int i = 0; i<n; i++) {
            int p = dsu.find(i);
            if(!mp.count(p)) {
                if(ch > 'z') return "";
                mp[p] = ch++;
            }
            ans[i] = mp[p];
        }

        cout<<"ans: "<<ans<<endl;

        // validations
        vector<vector<int>> calc(n, vector<int>(n));
        for(int i = n-1; i>=0; i--) {
            for(int j = n-1; j>=0; j--) {
                if(ans[i] == ans[j]) {
                    calc[i][j] = 1;
                    if(i+1 < n and j+1 < n)
                        calc[i][j] += calc[i+1][j+1];
                }
            }
        }

        if(calc == lcp) return ans;
        return "";
    }
};