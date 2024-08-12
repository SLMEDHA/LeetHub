class Solution {
public:
    string largestOddNumber(string num) {
     for (int i = num.size() - 1; i >= 0; --i) {
            if ((num[i] - '0') % 2 != 0) {
                // Return the substring from the start to the current digit
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit was found, return an empty string
        return "";
    }
};