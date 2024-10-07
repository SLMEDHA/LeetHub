class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if (intervals.empty()) return {};
        
        // Sort intervals by the starting value
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged; // To store the merged intervals
        
        // Initialize the merged list with the first interval
        merged.push_back(intervals[0]);
        
        // Iterate through the intervals
        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last merged interval
            vector<int>& last = merged.back();
            
            // If the current interval overlaps with the last one, merge them
            if (intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // If it doesn't overlap, add the current interval to merged
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};