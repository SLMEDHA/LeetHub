class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {//remove small element
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
