class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        vector<int> f(26,0);
        for(int i=0; i<s.size(); i++){
            f[s[i]-'a']++;
            f[t[i]-'a']--;

        }
        for(int i:f){
            if(i!=0){
                return false;
            }
        }
        return true;

    }
};
