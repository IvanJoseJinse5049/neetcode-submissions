class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        int m=min(n1,n2);
        string ans;
        int index=0;
        for(int k=0; k<m; k++){
            index=k;          
            ans.push_back(word1[index]);
            ans.push_back(word2[index]);
        }
        index=m;
        while(index<n1){
            ans.push_back(word1[index]);
            index++;
        }
        while(index<n2){
            ans.push_back(word2[index]);
            index++;
        }
        return ans;
    }
};