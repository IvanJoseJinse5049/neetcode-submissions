class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        for(char x:t){
            need[x]++;
        }
        int have=0;
        int needcount=need.size();
        unordered_map<char,int> window;
        int left=0;
        int minLen=INT_MAX;
        int start=0;
        for(int right=0; right<s.size(); right++){
            window[s[right]]++;
            if(need.find(s[right])!=need.end() && window[s[right]]==need[s[right]]){
                have++;
            }
            while(have==needcount){
                int currLen = right-left+1;
                if (currLen<minLen) {
                    minLen= currLen;
                    start= left;
                }
                
                if(window[s[left]]==need[s[left]]){
                    have--;
                }
                window[s[left]]--;
                left++;
            }

        }
        if(minLen==INT_MAX) return "";
        string ans="";
        for(int i=start; i<start+minLen; i++){
            ans.push_back(s[i]);
        }
        return ans;

    }
};
