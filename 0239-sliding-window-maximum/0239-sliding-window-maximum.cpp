class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return {};
        
        vector<int> left(n), right(n);
        vector<int> result;
        
        // Build left array
        for (int i = 0; i < n; i++) {
            if (i % k == 0) left[i] = nums[i];
            else left[i] = max(left[i-1], nums[i]);
        }
        
        // Build right array
        right[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            if ((i+1) % k == 0) right[i] = nums[i];
            else right[i] = max(right[i+1], nums[i]);
        }
        
        // Build result
        for (int i = 0; i <= n-k; i++) {
            result.push_back(max(right[i], left[i+k-1]));
        }
        
        return result;
    }
};