class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return{}; 
        double maxi=INT_MIN;
        double pro=1,subarray=1;
        for(int i=0;i<n;i++){
            pro*=nums[i];//from start
            subarray*=nums[n-1-i];//from end
            maxi=max({maxi,pro,subarray});
            if(pro==0)pro=1;
            if(subarray==0)subarray=1;

        }
        return maxi;
    }
};