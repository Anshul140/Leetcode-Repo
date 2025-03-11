class Solution {
public:
    const int mod = 1e9+7;

    long long modExp(long long base, long long exp){
        long long res = 1;

        while(exp > 0){
            if(exp % 2 == 1){
                res *= base;
                res %= mod;
            }
            base *= base;
            base %= mod;
            exp /= 2;
        }

        return res%mod;
    }

    int countGoodNumbers(long long n) {
        if(n % 2 == 0)
           return (modExp(4, (n/2))*modExp(5, (n/2)))%mod;
        else {
            long long x = (n/2)+1;
            cout<<"x + (n/2) = "<<x+(n/2)<<endl;
            return (modExp(4, (n/2))*modExp(5, x))%mod;
        }
    }
};