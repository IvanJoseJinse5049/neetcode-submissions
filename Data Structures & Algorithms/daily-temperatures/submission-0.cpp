class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size(),0);
        for(int i=temperatures.size()-1; i>=0; i--){
            int count=0;
            while(s.size()>0 && temperatures[s.top()]<=temperatures[i]){
                s.pop();
                count++;
            }
            if(s.size()>0 && temperatures[s.top()]>temperatures[i]){
                ans[i]=s.top()-i;
            }
            
            s.push(i);
        }
        return ans;

    }
};
