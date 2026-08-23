class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int> f;
        for(int i=0; i<s.size(); i++){
            f[s[i]]++;
            f[t[i]]--;

        }
        for(auto i:f){
            if(i.second!=0){
                return false;
            }
        }
        return true;

    }
};
