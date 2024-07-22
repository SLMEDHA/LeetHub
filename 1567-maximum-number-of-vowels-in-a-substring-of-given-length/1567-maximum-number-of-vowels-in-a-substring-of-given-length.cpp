class Solution {
public:
    int maxVowels(string s, int k) {
     unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxVowelCount = 0;
        int currentVowelCount = 0;
        
        // Count vowels for 1st time
        for (int i = 0; i < k; ++i) {
            if (vowels.count(s[i])) {
                currentVowelCount++;
            }
        }
        maxVowelCount = currentVowelCount;
        
        // Slide the window across the string
        for (int i = k; i < s.length(); ++i) {
            if (vowels.count(s[i])) {
                currentVowelCount++;
            }
            if (vowels.count(s[i - k])) {
                currentVowelCount--;
            }
            maxVowelCount = max(maxVowelCount, currentVowelCount);
        }
        
        return maxVowelCount;
    }
};