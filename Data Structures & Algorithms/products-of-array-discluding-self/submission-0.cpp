class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        int pre=nums[0];
        for(int i=1; i<n; i++){
            ans[i]=pre;
            pre*=nums[i];
        }
        int post=nums[n-1];
        for(int i=n-2; i>=0; i--){
            ans[i]=ans[i]*post;
            post*=nums[i];
        }
        return ans;

    }
};
