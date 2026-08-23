class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        vector<vector<int>> v(nums.size()+1);
        for(auto x:freq){
            v[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i=nums.size(); i>0; i--){
            if(k==0){
                break;
            }
            if(!v[i].empty()){
                for(int x:v[i]){
                    if(k!=0){
                       ans.push_back(x);
                       k--;
                    }

                }
            }
            
        }
        return ans;
    }
};
