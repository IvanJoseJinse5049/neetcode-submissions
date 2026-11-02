class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0;
        while( i<arr.size() && arr[i]<x){
            i++;
        }
        int right= i;
        int left= i-1;
        while(k>0){
            if(left<0){
                right++;
                k--;

            }else if(right==arr.size()){
                left--;
                k--;
            }else{
                if(abs(arr[left] - x) <= abs(arr[right] - x)){
                    left--;
                    k--;
                }else{
                    right++;
                    k--;
                }

            }
        }
        vector<int> ans;
        for(int i=left+1; i<=right-1; i++){
            ans.push_back(arr[i]);
        }
        return ans;

    }
};