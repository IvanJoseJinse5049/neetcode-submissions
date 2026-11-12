
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for (auto i : points) {
            int dis = (i[0] * i[0]) + (i[1] * i[1]);

            if (pq.size() < k) {
                pq.push({dis, i});
            }
            else if (dis < pq.top().first) {
                pq.pop();
                pq.push({dis, i});
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto point = pq.top().second;
            ans.push_back(point);
            pq.pop();
        }

        return ans;
    }
};
