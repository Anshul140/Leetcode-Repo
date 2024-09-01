class Solution {
public:
    int dc(char ch, int n) {
        if((ch == 'a' || ch == 'c' || ch == 'e' || ch == 'g') && (n%2 == 1)) return 0;

        if((ch == 'b' || ch == 'd' || ch == 'f' || ch == 'h') && (n%2 == 0)) return 0;

        return 1;
    }
    
    bool checkTwoChessboards(string s1, string s2) {
        char ch1 = s1[0], ch2 = s2[0];
        int n1 = s1[1] - '0';
        int n2 = s2[1] - '0';

        int col1 = 0, col2 = 0;
        col1 = dc(ch1, n1);
        col2 = dc(ch2, n2);

        // cout<<"ch1: "<<ch1<<" n1: "<<n1<<" col1: "<<col1<<endl;
        // cout<<"ch2: "<<ch2<<" n2: "<<n2<<" col2: "<<col2<<endl;
        return col1 == col2;
    }
};