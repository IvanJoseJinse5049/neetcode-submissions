class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary Search on answer pattern. *imp
        int left=1;
        int right= *max_element(piles.begin(),piles.end());
        while(left<right){
            long long m = left + (right-left)/2;
            long long hrs = 0;
            for(int x:piles){
                // always use double for more precision.
                hrs+=ceil(double(x)/m); // calculate total time
            }
            if(hrs<=h){
                right=m; // include the value in the set of possible answers
            }else{
                left=m+1; // ignore the value and everything less than that
            }
        }
        return left;
    }
};
