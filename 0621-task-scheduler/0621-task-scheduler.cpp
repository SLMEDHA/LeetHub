class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());//descending
        int maxFreq = freq[0];
        int idleTime = (maxFreq - 1) * n;   
        // Reduce idle time by placing other tasks
        for (int i = 1; i < 26; i++) {
            idleTime -= min(freq[i], maxFreq - 1);
        }       
        // If idleTime is negative, it means we have enough tasks to fill all idle slots
        idleTime = max(0, idleTime);  
        // Total intervals is the sum of task count and remaining idle time
        return tasks.size() + idleTime;
    }
};