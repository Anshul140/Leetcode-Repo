class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp1(26), mp2(26);
        for(auto it: s) mp1[it - 'a']++;
        for(auto it: t) mp2[it - 'a']++;
        
        for(int i = 0; i<26; i++) if(mp1[i] != mp2[i]) return false;
        
        return true;
    }
};