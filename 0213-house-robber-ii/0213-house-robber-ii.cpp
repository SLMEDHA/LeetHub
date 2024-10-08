class Solution {
public:
    // Helper function to solve the "House Robber" problem for a linear array
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;  // Two variables to store the previous two results
        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;  // Update prev2 to prev1 for the next iteration
            prev1 = curr;   // Update prev1 to current for the next iteration
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // If only one house, rob it
        if (n == 2) return max(nums[0], nums[1]);  // If two houses, rob the max of the two
        
        // Rob from house 1 to n-1, and from house 2 to n, then take the max
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};