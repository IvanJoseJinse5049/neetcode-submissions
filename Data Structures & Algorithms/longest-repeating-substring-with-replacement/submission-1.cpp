class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> m;
        int left=0;
        int maxfreq=0;
        int ans=0;
        for(int right=0; right<s.size(); right++){
            m[s[right]]++;
            maxfreq=max(maxfreq,m[s[right]]);
            while(!(right-left+1-maxfreq<=k)){
                m[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            

        }
        return ans;
    }
};
