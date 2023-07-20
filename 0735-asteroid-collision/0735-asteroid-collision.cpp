class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        
        while(true) {
            // breaking condition, if no possible collision can happen
            int f = 0;
            for(int i = 1; i<arr.size(); i++) {
                if(arr[i] < 0 and arr[i-1] > 0) {
                    f = 1;
                    break;
                }
            }
            if(f == 0) return arr;
            
            // breaking condition, after all collision
            int pos = 0, neg = 0;
            for(int el: arr) {
                cout<<el<<"  ";
                if(el > 0) pos++;
                else if(el < 0) neg++;
            }
            
            cout<<endl;
            if(pos == 0 or neg == 0) return arr;
            
            // pos and neg exists
            stack<int> st;
            for(int el: arr) {
                if(st.size() == 0) st.push(el);
                else {
                    if(el < 0 and st.top() > 0) {
                        int temp = st.top();
                        int v1 = abs(st.top());
                        int v2 = abs(el);
                        st.pop();
                        
                        if(v1 > v2) st.push(temp);
                        else if(v1 < v2) st.push(el);
                    } else {
                        st.push(el);
                    }
                }
            }
            
            arr.clear();
            while(!st.empty()) {
                arr.push_back(st.top());
                st.pop();
            }
            reverse(arr.begin(), arr.end());
        }
        
        return arr;
    }
};