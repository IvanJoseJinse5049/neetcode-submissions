class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(auto i:tokens){
            if(i!="+" && i!="-" && i!="/" && i!="*"){
                s.push(stoi(i));
            }else{
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                int val=0;
                if(i=="+"){
                    val=a+b;
                }else if(i=="-"){
                    val=a-b;
                }else if(i=="/"){
                    val=a/b;
                }else{
                    val=a*b;
                }
                s.push(val);
            }
        }
        return s.top();
    }
};
