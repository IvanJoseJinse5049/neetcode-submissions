class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string component;
        vector<string> directories;
        while(getline(ss,component,'/')){
            if(component=="" || component=="."){
                continue;
            }else if(component==".."){
                if(!directories.empty()){
                    directories.pop_back();
                } 
            }else{
                directories.push_back(component);
            }
        }
        string res="/";
        for(string i : directories){
            res+=(i);
            res+=("/");
        }
        if(res.size()>1){
            res.pop_back();
        }
        return res;
    }
};