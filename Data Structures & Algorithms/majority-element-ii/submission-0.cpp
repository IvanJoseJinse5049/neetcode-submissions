class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int a=0;
        int b=1;
        int counta=0,countb=0;
        for(int i=0; i<nums.size(); i++){        
            if(nums[i]==a){
                counta++;
            }else if(nums[i]==b){
                countb++;
            }else if(counta==0){
                a=nums[i];
                counta=1;
            }else if(countb==0){
                b=nums[i];
                countb=1;
            }else{
                counta--;
                countb--;
            }
        }
        int freqa=0,freqb=0;
        for(int num:nums){
            if(num==a){
                freqa++;
            }else if(num==b){
                freqb++;
            }
        }
        if(freqa>n/3){
            ans.push_back(a);
        }
        if(freqb>n/3){
            ans.push_back(b);
        }
        return ans;
    }
};