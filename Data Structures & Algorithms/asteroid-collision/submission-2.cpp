class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i:asteroids){
            bool destroyed=false;
            while(s.size()>0 && s.top()>0 && i<0){
                int a=s.top();
                if(abs(a)>abs(i)){
                    destroyed=true;
                    break;
                }else if(abs(a)<abs(i)){
                    s.pop();
                }else if(abs(a)==abs(i)){
                    s.pop();
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed){
                s.push(i);
            }

        }
        vector<int> ans(s.size(),0);
        for(int i=ans.size()-1; i>=0; i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};