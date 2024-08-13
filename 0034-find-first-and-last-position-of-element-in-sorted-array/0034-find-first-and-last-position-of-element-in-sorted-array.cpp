class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     vector<int> result(2, -1);  // Initialize with [-1, -1]

        // Find the first position of the target
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (nums[mid] == target) result[0] = mid;
        }

        // Find the last position of the target
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (nums[mid] == target) result[1] = mid;
        }

        return result;
    }
};