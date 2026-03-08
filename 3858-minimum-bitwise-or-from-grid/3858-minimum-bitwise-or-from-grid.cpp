class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = 0;
        int forbidden = 0;

        for(int i = 31; i>=0; i--) {
            // possible -> tells if final answer can have this ith bit as 0 or not
            // true: possible to have 0, false: it will be 1
            bool possible = true;
            int mask = forbidden | (1 << i);

            // iterate over each row of grid
            for(auto v: grid) {
                
                bool ok = false;

                for(int el: v) {
                    if((el & mask) == 0) {
                        ok = true;
                        break;
                    }
                }

                if(!ok) {
                    possible = false;
                    break;
                }
            }

            if(!possible) {
                // set ith bit
                ans |= (1<<i);
            } else {
                forbidden = mask;
            }
        }

        return ans;
    }
};