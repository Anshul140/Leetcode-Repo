class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans, temp;
        
        for(auto it: words) {
            string word="";
            for(auto ch: it) {
                if(isalpha(ch) or ch != separator) word += ch;
                else {
                    if(word.size() > 0) temp.push_back(word);
                    word = "";
                }
            }
            if(word.size() > 0) temp.push_back(word);
        }
        
        // for(auto it: temp) cout<<it<<"  ";
        // cout<<endl;
        return temp;
    }
};