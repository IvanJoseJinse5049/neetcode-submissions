class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest=0;
        for(int i:s){
            if(s.find(i-1)==s.end()){
                int cur=i;
                int length=1;
                while(s.find(cur+1)!=s.end()){
                    cur++;
                    length++;
                }
                longest=max(length,longest);
            }
        }
        return longest;
    }
};
