class Solution {
public:
    string removeOuterParentheses(string s) {
     string result;
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If depth > 0, this is not an outermost '(', so add it to the result
                if (depth > 0) {
                    result += c;
                }
                depth++;  // Increase the depth
            } else if (c == ')') {
                depth--;  // Decrease the depth
                // If depth > 0, this is not an outermost ')', so add it to the result
                if (depth > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};