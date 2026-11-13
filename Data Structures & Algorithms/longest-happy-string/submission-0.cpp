
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();

            int freq = first.first;
            char ch = first.second;

            int n = ans.size();

            // Check whether adding ch creates three consecutive characters
            if (n >= 2 && ans[n - 1] == ch && ans[n - 2] == ch) {

                // No alternative character available
                if (pq.empty()) {
                    break;
                }

                // Use the second most frequent character
                auto second = pq.top();
                pq.pop();

                ans += second.second;
                second.first--;

                if (second.first > 0) {
                    pq.push(second);
                }

                // Put the unused first character back
                pq.push(first);
            }
            else {
                // Safely use the most frequent character
                ans += ch;
                freq--;

                if (freq > 0) {
                    pq.push({freq, ch});
                }
            }
        }

        return ans;
    }
};
