class Solution {
public:
    int compress(vector<char>& chars) {
       int n = chars.size();
        int write = 0; // Index to write the result
        int i = 0; // Index to read the characters

        while (i < n) {
            char currentChar = chars[i];
            int count = 0;

            // Count the number of occurrences of the current character
            while (i < n && chars[i] == currentChar) {
                ++i;
                ++count;
            }

            // Write the character to the result
            chars[write++] = currentChar;

            // Write the count if it's more than 1
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};