#include <vector>

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> c(26, 0);
        for (char ca : s) {
            c[ca-'a']++;
        }
        vector<int> ct(26, 0);
        for (int i = 0; i < 26; i++) {
            if (c[i]==1) {
                ct[i]=1;
            }
        }
        deque<char> q;
        vector<int> used(26, 0);
        for (char ca : s) {
            while (q.size()>0 && q.back()>ca && c[q.back()-'a']>1 && used[ca-'a']==0) {
                c[q.back()-'a']--;
                used[q.back()-'a']=0;
                q.pop_back();
            }
            if (used[ca-'a']==0 || q.back()==ca) {
                q.push_back(ca);
                used[ca-'a']++;
            } else {
                c[ca-'a']--;
            }
        }
        vector<int> used2(26, 0);
        string ans="";
        while (q.size()>0) {
            char t = q.front();
            if (used2[t-'a']==0) {
                used2[t-'a']=1;
                ans+=t;
            }
            q.pop_front();
        }
        for (int i = 0; i < 26; i++) {
            if (c[i]>0 && used2[i]==0) {
                ans+=(char)(i+'a');
            }
        }
        return ans;
    }
};