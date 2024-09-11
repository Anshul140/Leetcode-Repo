class Solution {
public:
    int minimumBuckets(string s) {
        if(s == ".") return 0;
        if(s == "H") return -1;

        int n = s.size();

        // size 3 check
        int ans = 0;
        for(int i = 0; i<n-2; i++){
            if(s[i] == 'H' and s[i+1] == 'H' and s[i+2] == 'H')
                return -1;

            if(s[i] == 'H' and s[i+1] == '.' and s[i+2] == 'H'){
                ans++;
                s[i] = 'x';
                s[i+2] = 'x';
            } 
        }

        // cout<<"dbg 3 -> ans: "<<ans<<endl;
        // size 2 check
        for(int i = 0; i<n; i++){
            if(i < n-1 and s[i] == '.' and s[i+1] == 'H'){
                ans++;
                s[i+1] = 'x';
            }

            if(i > 0 and s[i] == '.' and s[i-1] == 'H'){
                ans++;
                s[i-1] = 'x';
            }
        }

        for(int i = 0; i<n; i++) {
            if(s[i] == 'H') return -1;
        }
        return ans;
    }
};