class Solution {
public:
    int minDeletions(string s) {
        vector<int> c(26);
        for (auto ch : s) {
            c[ch-'a']++;
        }
        sort(c.begin(),c.end(),greater<int>());
        int ans=0;
        map<int,int> seen;
        seen[c[0]]=1;
        for (int i = 1; i < 26; i++) {
            while (c[i]>0 && seen[c[i]]) {
                c[i]--;
                ans++;
            }
            if (c[i]!=0) {
                seen[c[i]]=1;
            }
        }
        return ans;
    }
};