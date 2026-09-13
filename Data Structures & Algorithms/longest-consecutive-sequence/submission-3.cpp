class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest=0;
        for(int i:s){
            if(s.find(i-1)==s.end()){
                int curr=i;
                int len=1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    len++;
                }
                longest=max(longest,len);
            }
        }
        return longest;
    }
};
