class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         int n = nums.size();
        double currentSum = 0;
        // Compute the sum of the first window of size k
        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
        }
        
        // Initialize maxAverage with the average of the first window
        double maxAverage = currentSum / k;
        
        // Slide the window and compute maxAverage
        for (int i = k; i < n; ++i) {
            currentSum += nums[i] - nums[i - k]; // Slide the window
            maxAverage = max(maxAverage, currentSum / k);
        }
        
        return maxAverage;
    }
};