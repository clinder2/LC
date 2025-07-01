class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<int> m(100001,0);
        for (auto p : properties) {
            m[p[0]]=max(m[p[0]],p[1]);
        }
        vector<int> m2(100001,0);
        m2[100000]=m[100000];
        for (int i = 99999; i>=0;i--) {
            m2[i]=max(m[i], m2[i+1]);
        }
        int ans=0;
        for (auto p : properties) {
            if (p[0]+1<100001 && p[1]<m2[p[0]+1]) {
                ans++;
            }
        }
        return ans;
    }
};