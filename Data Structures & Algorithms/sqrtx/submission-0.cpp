class Solution {
public:
    int mySqrt(int n) {
    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (1LL * mid * mid == n) {
            return mid;
        }
        else if (1LL * mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
    }
};