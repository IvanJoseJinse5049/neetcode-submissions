class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> sortedTasks;
        for(int i=0; i<tasks.size(); i++){
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedTasks.begin(),sortedTasks.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i=0;
        int time=0;
        vector<int> ans;
        while(ans.size()<tasks.size()){

            while(i<tasks.size() && sortedTasks[i][0]<=time){
                int processingTime = sortedTasks[i][1];
                int index = sortedTasks[i][2];
                pq.push({processingTime, index});
                i++;
            }
            if(pq.empty()){
                time=sortedTasks[i][0];
            }else{
                auto [processingTime, index] = pq.top();
                pq.pop();
                ans.push_back(index);
                time += processingTime;
            }
        }
        return ans;

    }
};