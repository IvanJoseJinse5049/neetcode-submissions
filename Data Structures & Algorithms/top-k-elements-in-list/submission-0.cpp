class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        vector<pair<int,int>> freq;
        for(auto i:m){
            freq.push_back({i.second,i.first});
        }
        sort(freq.begin(),freq.end());
        vector<int> ans;
        int idx=freq.size()-1;
        for(int i=0; i<k; i++){
            ans.push_back(freq[idx--].second);
        }
        return ans;

        
    }
};
