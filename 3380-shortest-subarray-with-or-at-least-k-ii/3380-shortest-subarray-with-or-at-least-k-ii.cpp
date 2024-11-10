class Solution {
public:
    long long convertBinStrToInt(string binaryString){
        bitset<64> bitsetValue(binaryString);
        return bitsetValue.to_ullong();
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        long long n = nums.size(), i = 0, j = 0;
        long long ans = n+1, aror = nums[0];

        vector<int> pref(64);

        while(j < n) {
            bitset<64> x(nums[j]);
            for(int b = 0; b<64; b++){
                pref[b] += x.test(b);
            }

            aror |= nums[j];
            while(aror >= k and i <= j){
                ans = min(ans, (j - i + 1));
                bitset<64> f(nums[i]);
                // cout<<"window start value: "<<f<<endl;
                string temp = "";

                for(int y = 0; y<64; y++){
                    if((f.test(y) and pref[y] == 1) or (pref[y] == 0)) 
                        temp.push_back('0');
                    else
                        temp.push_back('1');
                    pref[y] -= f.test(y);
                }
                reverse(temp.begin(), temp.end());
                // cout<<"str: "<<temp<<endl;
                // cout<<"str's int: "<<convertBinStrToInt(temp)<<endl;
                aror = convertBinStrToInt(temp);
                i++;
            }
            j++;
        }

        return (ans == n+1)? -1: ans;
    }
};