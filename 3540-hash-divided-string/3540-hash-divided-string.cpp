class Solution {
public:
    string stringHash(string s, int k) {
        // map<char, int> cimp;
        map<int, char> icmp;

        char t = 'a';
        for(int i = 0; i<26; i++, t++){
            // cimp[t] = i;
            icmp[i] = t;
        }

        string ans = "", temp = "";
        int n = s.size();

        for(int i = 0; i<n; i++){
            temp.push_back(s[i]);
            if(temp.size() == k) {
                int sum = 0;
                for(char c: temp){
                    sum += c - 'a';
                }
                sum = sum%26;
                ans.push_back(icmp[sum]);
                temp = "";
            }
        }

        if(temp.size() == k) {
            int sum = 0;
            for(char c: temp){
                sum += c - 'a';
            }
            sum = sum%26;
            ans.push_back(icmp[sum]);
            temp = "";
        }
        return ans;
    }
};