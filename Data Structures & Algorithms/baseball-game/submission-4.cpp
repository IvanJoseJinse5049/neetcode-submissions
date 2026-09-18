class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(auto i:operations){
            if(i=="+"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int val=a+b;
                s.push(b);
                s.push(a);
                s.push(val);
            }else if(i=="D"){
                int a=s.top();
                a=a*2;
                s.push(a);

            }else if(i=="C"){
                s.pop();
            }else{
                s.push(stoi(i));
            }
        }
        int sum=0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();

        }
        return sum;
    }
};