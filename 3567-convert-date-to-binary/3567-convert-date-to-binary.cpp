class Solution {
public:
    string stb(const string& str) {
        // Convert the string to an integer
        int num = stoi(str);

        // Convert the integer to a binary string using std::bitset
        bitset<32> binary(num);  // assuming 32-bit integer
        
        string binaryStr = binary.to_string();

        size_t firstOne = binaryStr.find('1');
        if (firstOne != std::string::npos) {
            return binaryStr.substr(firstOne);  // Return the substring starting from the first '1'
        }

        return "0";  
    }
    
    string convertDateToBinary(string d) {
        string y = d.substr(0, 4);
        string m = d.substr(5, 2);
        string dd = d.substr(8, 2);
        
        return stb(y)+"-"+stb(m)+"-"+stb(dd);
    }
};