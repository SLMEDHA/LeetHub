class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount;
        int n = s.length();
        
        // Count the frequency of each character
        for (int i = 0; i < n; ++i) {
            charCount[s[i]]++;
        }
        
        // Find the first character with a frequency of 1
        for (int i = 0; i < n; ++i) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;  
    }
};