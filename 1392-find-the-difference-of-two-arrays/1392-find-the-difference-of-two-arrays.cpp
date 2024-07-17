class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>result(2);

        unordered_set<int> set_nums1(nums1.begin(), nums1.end());
        unordered_set<int> set_nums2(nums2.begin(), nums2.end());
        
        unordered_set<int> not_in_nums1;
        unordered_set<int> not_in_nums2;
        
        // Find elements in nums1 not in nums2
        for (int num : nums1) {
            if (set_nums2.find(num) == set_nums2.end()) {
                not_in_nums1.insert(num);
            }
        }
        
        // Find elements in nums2 not in nums1
        for (int num : nums2) {
            if (set_nums1.find(num) == set_nums1.end()) {
                not_in_nums2.insert(num);
            }
        }
        
        // Convert sets to vectors
        result[0] = vector<int>(not_in_nums1.begin(), not_in_nums1.end());
        result[1] = vector<int>(not_in_nums2.begin(), not_in_nums2.end());
        
        return result;
    }
};