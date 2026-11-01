class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = 0;
        for(int i:prices){
            minPrice=min(minPrice,i);
            ans=max(ans,i-minPrice);
        }
        return ans;

    }
};
