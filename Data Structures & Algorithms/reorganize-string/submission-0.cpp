
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count character frequencies
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Create a max heap
        // {frequency, character}
        priority_queue<pair<int, char>> pq;

        for (auto entry : freq) {
            pq.push({entry.second, entry.first});
        }

        // Step 3: Check if reorganization is possible
        int maxFreq = 0;

        for (auto entry : freq) {
            maxFreq = max(maxFreq, entry.second);
        }

        if (maxFreq > (s.size() + 1) / 2) {
            return "";
        }

        // Step 4: Build the answer
        string result = "";

        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {

            // Get the most frequent available character
            pair<int, char> current = pq.top();
            pq.pop();

            // Add character to result
            result += current.second;

            // Decrease its frequency
            current.first--;

            // Reinsert previous character if available
            if (prev.first > 0) {
                pq.push(prev);
            }

            // Hold current character for next iteration
            prev = current;
        }

        return result;
    }
};
