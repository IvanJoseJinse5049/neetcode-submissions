class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices[0];
        int ans=0;
        for(int price:prices){
            m=min(m,price);
            int profit=price-m;
            ans=max(ans,profit);
        }
        return ans;
    }
};
