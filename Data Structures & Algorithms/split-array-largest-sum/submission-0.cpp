class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int sum = 0;
        int subarrays = 1;

        for (int i = 0; i < nums.size(); i++) {
            if(sum+nums[i]>maxSum){
                subarrays++;
                sum=nums[i];
            }else{
                sum+=nums[i];
            }
        }
        return subarrays<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};