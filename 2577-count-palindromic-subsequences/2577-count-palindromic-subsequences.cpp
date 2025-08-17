typedef long long ll;
ll MOD = 1e9 + 7;

class Solution {
public:
    int countPalindromes(string s)
    {
        int n = s.size();
        if (n < 5)
            return 0;

        vector<vector<vector<ll>>> dp_left(n+1, vector<vector<ll>>(11, vector<ll>(11)));

        vector<vector<vector<ll>>> dp_right(n+1, vector<vector<ll>>(11, vector<ll>(11)));

        vector<int> left(11), right(11);

        for (int i = 0; i < n; i++)
        {
            int cur = s[i] - '0';

            if (i > 0)
            {
                for (int first = 0; first <= 9; first++)
                {
                    for (int second = 0; second <= 9; second++)
                    {
                        dp_left[i][first][second] = dp_left[i - 1][first][second];

                        if (second == cur)
                        {
                            dp_left[i][first][second] += left[first];
                        }
                    }
                }
            }

            left[cur]++;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int cur = s[i] - '0';

            if (i < n - 1)
            {
                for (int first = 0; first <= 9; first++)
                {
                    for (int second = 0; second <= 9; second++)
                    {
                        dp_right[i][first][second] = dp_right[i + 1][first][second];

                        if (first == cur)
                        {
                            dp_right[i][first][second] += right[second];
                        }
                    }
                }
            }

            right[cur]++;
        }

        long long ans = 0;
        for (int i = 2; i < n - 2; i++)
        {

            for (int first = 0; first <= 9; first++)
            {
                for (int second = 0; second <= 9; second++)
                {
                    long long t1 = dp_left[i - 1][first][second] % MOD;
                    long long t2 = dp_right[i + 1][second][first] % MOD;
                    ans += (t1 * t2);
                    ans %= MOD;
                }
            }
        }

        return ans;
    }

};