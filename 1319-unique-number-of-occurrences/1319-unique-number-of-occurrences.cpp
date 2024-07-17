class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> countMap;
        
        // Step 1: Count occurrences of each element
        for (int num : arr) {
            countMap[num]++;
        }
        
        // Step 2: Count occurrences of each count
        unordered_map<int, int> occurrenceCount;
        for (auto& pair : countMap) {
            int count = pair.second;
            occurrenceCount[count]++;
        }
        
        // Step 3: Check if all occurrence counts are unique
        for (auto& pair : occurrenceCount) {
            if (pair.second > 1) {
                return false;
            }
        }
        
        return true;
    }
};