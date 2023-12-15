class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> inc, out;
        set<string> cities;
        for(auto it: paths) {
            out[it[0]]++;
            cities.insert(it[0]);
            cities.insert(it[1]);
        }
        
        for(auto it: cities) {
            if(!out.count(it)) return it;
        }
        
        return "";
    }
};