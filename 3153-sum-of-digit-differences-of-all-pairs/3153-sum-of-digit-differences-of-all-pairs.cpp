class Solution {
public:
    long long countDistinctPairs(vector<int>& arr) {
        long long freq[10] = {0};

        for (int num : arr) {
            freq[num]++;
        }

        long long pairCount = 0;
        set<pair<int, int>> sp;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (i != j and !sp.count({i, j})) {
                    sp.insert({i, j});
                    sp.insert({j, i});
                    pairCount += freq[i] * freq[j];
                }
            }
        }

        return pairCount;
    }
    
    vector<vector<int>> extractDigits(vector<int>& nums) {
        if (nums.empty()) return {};

        int numDigits = to_string(nums[0]).size();

        vector<vector<int>> result(numDigits);

        for (int num : nums) {
            for (int i = 0; i < numDigits; ++i) {
                int digit = (num / static_cast<int>(pow(10, numDigits - i - 1))) % 10;
                result[i].push_back(digit);
            }
        }

        return result;
    }
    
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> arr = extractDigits(nums);
        long long ans = 0;
        for(auto it: arr) {
            ans += countDistinctPairs(it);
        }
        
        return ans;
    }
};