class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        cout<<endl<<endl;
        long si, sj, fi, fj;
        if(sx <= fx) {
            si = sx;
            sj = sy;
            fi = fx;
            fj = fy;
        } else {
            si = fx;
            sj = fy;
            fi = sx;
            fj = sy;
        }
        
        if(fj < sj) {
            fj += 2*abs(fj-sj);
        }
         
        if(fj - sj <= fi - si) {
            long diff = fj-sj;
            long time = diff + abs(si + diff - fi);
            if(time == 0 and t == 1) return false;
            return (t >= time);
        } else {
            long diff = fi - si;
            long time = diff + abs(sj + diff - fj);
            if(time == 0 and t == 1) return false;
            return (t >= time);
        }
    }
};
