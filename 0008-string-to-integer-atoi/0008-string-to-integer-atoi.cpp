class Solution {
public:
    // - - - - + 1 2 3 4 a h  a
    // 0 1 2 3 4 5 6 7 8 9 10 11
    string removeLeadingChars(string s, char ch){
        int start = 0;
        while(start < s.size() and s[start] == ch) start++;
        
        if(start == s.size()) return "";

        return s.substr(start, s.size()-start);
    }

    int myAtoi(string s) {
        cout<<"s: " <<s<<endl;
        // i) step Whitespace
        string s1 = removeLeadingChars(s, ' ');
        cout<<"s1: "<<s1<<endl;

        if(s1 == "") return 0;

        // ii) step Signedness
        bool positive = true;
        string s2 = s1;
        if(s1[0] == '-' or s1[0] == '+'){
            if(s1[0] == '-' and s1.size() > 1) {
                positive = false;
                s2 = s1.substr(1, s1.size()-1);
            } else if(s1[0] == '+' and s1.size() > 1){
                s2 = s1.substr(1, s1.size()-1);
            } else if(s1.size() == 1) {
                return 0;
            }
        }

        cout<<"s2: "<<s2<<endl;
        // iii) conversion
        string s3 = s2;
        // if(s3 == "") return 0;

        // cout<<"s3: "<<s3<<endl;
        int start = 0;
        while(start < s3.size() and s3[start] == '0'){
            start++;
        }

        if(start == s3.size() || !isdigit(s3[start])) return 0;
        string s4 = s3.substr(start, s3.size()-start);

        start = 0;
        while(start < s4.size() and isdigit(s4[start])){
            start++;
        }

        long long int one = 1;
        long long int x = one << 31, mx = x-1, mn = (-1)*x;

        if(start > 10){
            if(positive) return mx;
            else return mn;
        }

        string s5 = s4.substr(0, start);

        cout<<"s5: "<<s5<<endl;
        unsigned long long int temp = stoull(s5);

        cout<<"temp: "<<temp<<endl;
        cout<<"mx: "<<mx<<endl;
        if(temp >= mx) {
            if(positive) return mx;
            else {
                if(temp == mx) return (-1)*mx;
                else return mn;
            }
        }

        if(positive) return temp;
        else return (-1)*temp;
        return 0;
    }
};