class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(auto i:strs){
            vector<int> freq(26,0);
            for(auto x:i){
                freq[x-'a']++;
            }
            string s;
            for(int l:freq){
                s+=to_string(l)+"#";
            }
            m[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};
