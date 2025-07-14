typedef long long ll;
#define forsn(i,s,e) for(ll i = s; i < e; i++)

bool compareByThirdElement(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

class Solution {
public:
    struct DSU{
        ll n;
        //ll max_sized_component;
        vector<ll> parent, size;

        DSU(ll N) {
            n = N;
            // max_sized_component = 1;
            parent.resize(n+5);
            size.resize(n+5);

            forsn(i, 1, n+1) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        ll find(ll x) {
            while(x != parent[x]) x = parent[x];
            return x;
        }

        bool same(ll a, ll b) {
            return find(a) == find(b);
        }

        void unite(ll a, ll b) {
            a = find(a);
            b = find(b);

            // if b size is greater than a, than swap
            if(size[a] < size[b]) swap(a, b);

            // now this position ensures that a's size is definitely larger than b
            // always add smaller cluster to large cluster

            size[a] += size[b];
            //max_sized_component = max({max_sized_component, size[a], size[b]});
            parent[b] = a;
        }
    };

        
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if(k == n) return 0;
        if(edges.size() == 1) return edges[0][2];

        sort(edges.begin(), edges.end(), compareByThirdElement);

        vector<vector<int>> filtered_edges;
        DSU dsu(n+1);
        for(auto it: edges) {
            if(!dsu.same(it[0], it[1])) {
                filtered_edges.push_back(it);
                dsu.unite(it[0], it[1]);
            }
        }

        vector<int> wts;
        for(auto it: filtered_edges) {
            // cout<<"a: "<<it[0]<<" b: "<<it[1]<<" c: "<<it[2]<<endl;
            wts.push_back(it[2]);
        }

        sort(wts.begin(), wts.end());
        reverse(wts.begin(), wts.end());
        int wsz = wts.size();
        
        if(k > wsz) k = wsz;

        // cout<<
        return wts[k-1];
    }
};