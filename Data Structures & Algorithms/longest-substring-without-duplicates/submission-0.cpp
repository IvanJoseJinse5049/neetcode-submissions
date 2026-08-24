class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> m;
        int left=0;
        int ans=0;
        for(int right=0; right<s.size(); right++){
            while(m.find(s[right])!=m.end() && m[s[right]]>0){
                m[s[left]]--;
                left++;
            }
            int len=right-left+1;
            ans=max(ans,len);
            m[s[right]]++;
        }
        return ans;
    }
};
