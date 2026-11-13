
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();

        // Store {enqueueTime, processingTime, originalIndex}
        vector<vector<int>> sortedTasks;

        for (int i = 0; i < n; i++) {
            sortedTasks.push_back({
                tasks[i][0],
                tasks[i][1],
                i
            });
        }

        // Sort tasks by enqueue time
        sort(sortedTasks.begin(), sortedTasks.end());

        // Min Heap: {processingTime, originalIndex}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans;

        long long time = 0;
        int i = 0;

        while (ans.size() < n) {

            // Insert all tasks that have arrived
            while (i < n && sortedTasks[i][0] <= time) {

                int processingTime = sortedTasks[i][1];
                int index = sortedTasks[i][2];

                pq.push({processingTime, index});

                i++;
            }

            // If no task is available, jump to next arrival
            if (pq.empty()) {
                time = sortedTasks[i][0];
            }
            else {

                // Get the task with highest priority
                auto [processingTime, index] = pq.top();

                pq.pop();

                // Record the executed task
                ans.push_back(index);

                // Update CPU time
                time += processingTime;
            }
        }

        return ans;
    }
};
