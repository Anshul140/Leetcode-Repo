class Solution {
public:
    int minMutation(string start, string end, vector<string>& wl) {
        int ans = 0;
        int n = wl.size();
        
        unordered_set<string> ss;
        for(auto &it: wl) ss.insert(it);
        
        if(!ss.count(end))
            return -1;
        
        queue<string> q;
        q.push(start);
        
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            for(int i = 0; i<sz; i++) {
                string curr = q.front();
                q.pop();
                
                for(int j = 0; j<curr.size(); j++) {
                    string temp = curr;
                    
                    for(char ch = 'A'; ch<='Z'; ch++) {
                        temp[j] = ch;
                        
                        if(temp == curr)
                            continue;
                        if(temp == end and ss.count(temp))
                            return ans;
                        if(ss.count(temp)) {
                            q.push(temp);
                            ss.erase(temp);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};