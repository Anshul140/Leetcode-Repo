class Solution {
public:
    bool canTransform(string s, string r) {
        int n = s.size();
        
        int i = 0, j = 0, lcs = 0, rcs = 0, lcr = 0, rcr = 0;
        while(j < n || i < n) {
            while(i < n and s[i] == 'X') i++;
            while(j < n and r[j] == 'X') j++;

            if(i == n and j == n) return true;
            if(i == n or j == n) return false;

            // ensure ordering
            if(s[i] != r[j]) return false;

            // ensure L direction constraint
            // Mandatory: (L: result_index ≤ start_index)
            if(s[i] == 'L' and i < j) return false;

            // ensure R direction constraint
            // Mandatory: (R: start_index ≤ final_index)
            if(s[i] == 'R' and i > j) return false;

            i++;
            j++;
        }
        
        return true;
    }
};