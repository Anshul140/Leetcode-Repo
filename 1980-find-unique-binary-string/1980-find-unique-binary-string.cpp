class Solution {
public:
    unordered_set<string> bs;

    void solve(int i, int n, string cur) {
        if(i == n) {
            bs.insert(cur);
            return;
        }

        solve(i+1, n, cur + "0");
        solve(i+1, n, cur + "1");
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string temp = "";
        solve(0, n, "");

        unordered_set<string> given;
        for(auto s: nums) given.insert(s);

        for(auto it: bs) {
            if(!given.count(it)) return it;
        }

        return "";
    }
};