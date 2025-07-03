class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string de = "/";
        int temp;
        int last=0;
        while ((temp=path.find(de, last))!=string::npos) {
            dirs.push_back(path.substr(last,temp-last));
            last=temp+1;
            //cout<<dirs.back()<<" dir\n";
        }
        dirs.push_back(path.substr(last));
        //cout<<dirs.back()<<" dir\n";
        string ans = "";
        vector<string> curr;
        for (int i = 0; i<dirs.size(); i++) {
            //cout<<dirs.size()<<" a\n";
            if (dirs[i]==".") {
                continue;
            } else if (dirs[i]=="..") {
                if (curr.size()>=1) {
                    curr.pop_back();
                }
            } else if (dirs[i].length()>0) {
                cout<<dirs[i]<<"\n";
                curr.push_back("/"+dirs[i]);
                //ans="/"+dirs[i]+ans;
            }
        }
        //cout<<curr.size();
        if (curr.size()==0) {
            return "/";
        }
        for (auto c : curr) {
            ans+=c;
        }
        return ans;
    }
};