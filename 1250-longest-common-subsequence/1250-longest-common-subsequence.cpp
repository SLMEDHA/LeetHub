class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
     int m = text1.length();
        int n = text2.length();
        
        // Create a 2D dp array with (m+1) x (n+1) size initialized to 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill the dp array
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match, add 1 to the previous diagonal value
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // Else, take the maximum of the values from top or left
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The result is the value in dp[m][n]
        return dp[m][n];
    }
};