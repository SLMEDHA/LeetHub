class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         if (intervals.empty()) return 0;

        // Sort intervals by their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int removals = 0;
        int prevEnd = intervals[0][1];  // Initialize the end of the first interval
        
        // Iterate through the sorted intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval's start is less than the previous end, they overlap
            if (intervals[i][0] < prevEnd) {
                removals++;  // Count the overlap (i.e., we need to remove this interval)
            } else {
                // Update the previous end to the current interval's end
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }
};