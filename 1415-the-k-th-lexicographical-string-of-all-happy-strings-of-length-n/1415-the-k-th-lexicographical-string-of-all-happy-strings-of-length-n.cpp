class Solution {
public:
    multiset<string> ms;
    int n;

    void solve(char prev, int i, string t) {
        if(i == n) {
            ms.insert(t);
            return;
        }

        if(prev == 'a') {
            t.push_back('b');
            solve('b', i+1, t);

            t.pop_back();
            t.push_back('c');
            solve('c', i+1, t);
        } 
        else if (prev == 'b') {
            t.push_back('c');
            solve('c', i+1, t);

            t.pop_back();
            t.push_back('a');
            solve('a', i+1, t);
        }
        else if(prev == 'c') {
            t.push_back('a');
            solve('a', i+1, t);

            t.pop_back();
            t.push_back('b');
            solve('b', i+1, t);
        }
    }

    string getHappyString(int N, int k) {
        string s = "";
        n = N;

        solve('a', 1, "a");
        solve('b', 1, "b");
        solve('c', 1, "c");

        int itr = 1;
        for(auto it: ms) {
            // cout<<it<<" ";
            if(itr == k) return it;
            itr++;
        }
        // cout<<endl;
        return s;
    }
};