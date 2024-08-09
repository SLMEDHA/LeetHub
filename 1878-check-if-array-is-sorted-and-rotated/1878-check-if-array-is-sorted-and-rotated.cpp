class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            // If there is more than one descending pair, return false.
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};