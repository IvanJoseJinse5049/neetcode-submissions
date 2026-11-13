
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Count frequencies
        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }

        // Max Heap
        priority_queue<int> pq;

        for (auto i : freq) {
            pq.push(i.second);
        }

        // {remaining frequency, available cycle}
        queue<pair<int, int>> cooldown;

        int cycle = 0;

        while (!pq.empty() || !cooldown.empty()) {

            cycle++;

            // Release tasks whose cooldown is complete
            if (!cooldown.empty() &&
                cooldown.front().second == cycle) {

                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            // Execute the highest-frequency task
            if (!pq.empty()) {

                int remaining = pq.top();
                pq.pop();

                remaining--;

                if (remaining > 0) {
                    cooldown.push({remaining, cycle + n + 1});
                }
            }
        }

        return cycle;
    }
};
