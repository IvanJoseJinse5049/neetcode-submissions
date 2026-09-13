class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int psum=0;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            psum+=nums[i];
            if(psum==k) count++;
            int val=psum-k;
            if(m.find(val)!=m.end()){
                count+=m[val];
            }
            m[psum]++;
        }
        return count;
    }
};