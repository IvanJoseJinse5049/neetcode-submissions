class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            int diff=first-second;
            if(diff!=0){
                pq.push(diff);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};
