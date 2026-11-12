class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char i:tasks){
            freq[i]++;
        }
        priority_queue<int> pq;
        for(auto i:freq){
            pq.push(i.second);
        }
        queue<pair<int,int>> cooldown;
        int cycle=0;
        while(!pq.empty() || !cooldown.empty()){
            cycle++;
            
            if(!cooldown.empty() && cooldown.front().second==cycle){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
            
            if(!pq.empty()){
                int remaining = pq.top();
                pq.pop();
                remaining--;
                if(remaining>0){
                    cooldown.push({remaining,cycle+n+1});
                }
            }

        }
        return cycle;
    }
};
