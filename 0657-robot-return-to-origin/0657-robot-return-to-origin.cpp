class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0, vertical = 0;
        for(char ch: moves) {
            if(ch == 'L') horizontal--;
            else if(ch == 'R') horizontal++;
            else if(ch == 'U') vertical++;
            else vertical--;
        }

        return horizontal == 0 and vertical == 0;
    }
};