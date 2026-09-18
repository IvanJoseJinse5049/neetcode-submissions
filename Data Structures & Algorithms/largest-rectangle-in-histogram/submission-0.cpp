class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int> right(heights.size(),0);
        for(int i=heights.size()-1; i>=0; i--){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=heights.size();
            }else{
                right[i]=s.top();
            }
            s.push(i);
        }
        vector<int> left(heights.size(),0);
        while(!s.empty()){
            s.pop();
        }
        for(int i=0; i<heights.size(); i++){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }else{
                left[i]=s.top();
            }
            s.push(i);

        }
        int ans=0;
        for(int i=0; i<heights.size(); i++){
            int width=right[i]-left[i]-1;
            int area=width*heights[i];
            ans=max(ans,area);
        }
        return ans;


        


    }
};
