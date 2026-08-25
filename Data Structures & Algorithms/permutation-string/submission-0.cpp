class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1;
        for(char x:s1){
            m1[x]++;
        }
        unordered_map<char,int> m2;
        for(int i=0; i<s1.size(); i++){
            m2[s2[i]]++;
        }
        if(m1==m2) return true;
        for(int i=s1.size(); i<s2.size(); i++){
            m2[s2[i-s1.size()]]--;
            m2[s2[i]]++;
            if(m2[s2[i-s1.size()]]==0){
                m2.erase(s2[i-s1.size()]);
            }
            if(m1==m2) return true;


        }
        return false;
    }
};
