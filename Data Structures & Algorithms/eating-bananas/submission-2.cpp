class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right= *max_element(piles.begin(),piles.end());
        while(left<right){
            long long m = left + (right-left)/2;
            long long hrs = 0;
            for(int x:piles){
                hrs+=ceil(double(x)/m);
            }
            if(hrs<=h){
                right=m;
            }else{
                left=m+1;
            }
        }
        return left;
    }
};
