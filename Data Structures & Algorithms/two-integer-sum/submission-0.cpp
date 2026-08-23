class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            int val=target-nums[i];
            if(m.find(val)!=m.end()){
                return {m[val],i};
            }else{
                m[nums[i]]=i;
            }

        }
    }
};
