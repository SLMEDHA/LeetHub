class Solution {
public:
    int search(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if the middle element is the target
            if (nums[mid] == target) {
                return mid;
            }
            
            // Determine which side is sorted
            if (nums[left] <= nums[mid]) { // Left side is sorted
                // Check if the target is within the sorted left side
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // Right side is sorted
                // Check if the target is within the sorted right side
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        // Target was not found
        return -1;
    }
};