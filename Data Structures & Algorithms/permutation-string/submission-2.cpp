class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()){
            return false;
        }
        unordered_map<char,int> m1;
        for(auto i:s1){
            m1[i]++;
        }
        unordered_map<char,int> m2;
        int left=0;
        for(int i=0; i<s1.size(); i++){
            m2[s2[i]]++;
        }
        if(m1==m2) return true;
        for(int right=s1.size(); right<s2.size(); right++){
            m2[s2[right]]++;
            m2[s2[left]]--;
            if(m2[s2[left]]==0) m2.erase(s2[left]);
            left++;
            if(m1==m2) return true;
        }
        return false;

        
    }
};
