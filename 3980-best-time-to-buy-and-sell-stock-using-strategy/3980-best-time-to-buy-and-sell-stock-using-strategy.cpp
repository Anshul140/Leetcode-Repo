class Solution {
public:
    long long maxProfit(vector<int>& p, vector<int>& s, int k) {
        long long ans = 0, curr = 0;
        long long n = p.size(), i = 0, j = 0, ws = 0;
        vector<long long> suf(n+1), pre(n+1);

        for(int x = 0; x<n; x++) {
            long long a = s[x], b = p[x];
            ans += a*b;
        }

        if(n < 3) {
            long long x = p[1];
            ans = max(ans, x);
            return ans;
        }

        for(int x = n-1; x >= 0; x--) {
            long long a = s[x], b = p[x];
            if(x == n-1) {
                suf[x] = a*b;
            } else {
                suf[x] = suf[x+1] + (a*b);
            }
        }

        for(int x = 0; x<n; x++) {
            long long a = s[x], b = p[x];
            if(x == 0){
                pre[0] = a*b;
            } else {
                pre[x] = pre[x-1] + (a*b);
            }
        }

        // cout<<"suffix: "<<endl;
        // for(auto it: suf) cout<<it<<"   ";
        // cout<<endl;

        // cout<<"prefix: "<<endl;
        // for(auto it: pre) cout<<it<<"   ";
        // cout<<endl;

        for(int i = 0; i<n; i++) {
            
            if(ws < k) {
                if(ws >= (k/2)) {
                    curr += p[i];
                }
                ws++;
            } else {
                if(j == 0) {
                    ans = max(ans, curr + suf[i]);
                } else {
                    ans = max(ans, pre[j-1] + curr + suf[i]);
                }
                curr -= p[j + (k/2)];
                curr += p[i];
                j++;

            }
            // cout<<"i: "<<i<<" ws: "<<ws<<" curr: "<<curr<<endl;
            // j++;
        }

        if(j > 0)
            ans = max(curr + pre[j-1], ans);
        else {
            ans = max(curr, ans);
        }
        return ans;
    }
};