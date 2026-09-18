class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> m;
        stack<float> s;
        for(int i=0; i<position.size(); i++){
            m[position[i]]=speed[i];
        }
        sort(position.rbegin(), position.rend());
        for(int i=0; i<position.size(); i++){
            int spd=m[position[i]];
            float time = float(target-position[i])/spd;
            if(s.size()>0 && s.top()>=time){
                continue;
            }else{
                s.push(float(time));
            }

        }
        return s.size();

    }
};
