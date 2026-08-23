class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c1=0;
        int c2=0;
        int c3=0;
        for(int i:nums){
            if(i==0) c1++;
            if(i==1) c2++;
            if(i==2) c3++;

        }
        int idx=0;
        while(c1>0){
            nums[idx++]=0;
            c1--;
        }
        while(c2>0){
            nums[idx++]=1;
            c2--;
        }
        while(c3>0){
            nums[idx++]=2;
            c3--;
        }
        
    }
};