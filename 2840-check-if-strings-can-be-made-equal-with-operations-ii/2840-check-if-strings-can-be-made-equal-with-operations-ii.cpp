class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> odd1(26), even1(26);
        vector<int> odd2(26), even2(26);

        for(int i = 0; i<n; i++) {
            if(i&1) {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            } else {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            }
        }

        return odd1 == odd2 and even1 == even2;
    }
};