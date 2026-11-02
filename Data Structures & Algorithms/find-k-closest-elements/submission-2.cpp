class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;

        while (r - l >= k) {
            if (abs(x - arr[l]) <= abs(x - arr[r])) {
                r--;  // right is farther, or tied: preserve smaller left value
            } else {
                l++;  // left is farther
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};