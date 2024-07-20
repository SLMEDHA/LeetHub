class Solution {
public:
    string reverseWords(string s) {       
    int start = 0, end = s.length() - 1;//trim spaces
        while (start <= end && s[start] == ' ') ++start;
        while (end >= start && s[end] == ' ') --end;
        
        // If the string is empty after trimming
        if (start > end) return "";

        // Step 2: Split words and store them in a vector
        vector<string> words;
        string word;
        for (int i = start; i <= end; ++i) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            }
        }
        if (!word.empty()) words.push_back(word); // Add the last word

        // Step 3: Reverse the order of words
        reverse(words.begin(), words.end());

        // Step 4: Join the words with a single space
        string result;
        for (string w : words) {
            if (!result.empty()) result += ' ';
            result += w;
        }
        
        return result;
    }
};