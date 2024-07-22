class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        sort(nums.begin(),nums.end());
        int count=0;
        while(left<right){
            if(nums[left]+nums[right]==k){
                count++;
                left++;
                right--;
            }
            else if(nums[left]+nums[right]>k){
                right--;
            }
            else{
                left++;
            }
        }
        return count;
    }
};