class Solution {
public: 
    int getMsb(bitset<32>& bs) {
        for(int i = 31; i>=0; i--) {
            if(bs.test(i)) return i;
        }
        return -1;
    }

    int bitwiseComplement(int n) {
        bitset<32> bs(n);
        cout<<bs<<endl;

        int msb = getMsb(bs);
        if(msb == -1) return 1;
        
        for(int i = msb; i >= 0; i--) {
            if(bs.test(i)) bs.reset(i);
            else bs.set(i);
        }

        unsigned long value = bs.to_ulong();
        return value;
    }
};