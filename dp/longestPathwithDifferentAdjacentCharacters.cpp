class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        if (parent.size()==1) {
            return 1;
        }
        vector<int> T(parent.size(), 1);
        vector<int> T1(parent.size());
        vector<int> T2(parent.size());
        map<int,int> count;
        map<int,int> seen;
        for (int i = 0; i < parent.size(); i++) {
            count[parent[i]]++;
            seen[parent[i]]=1;
        }
        queue<int> q;
        int ans=0;
        for (int i = 0; i < parent.size(); i++) {
            if (!seen[i]) {
                int p = parent[i];
                if (p>=0) {
                    if (s[i]!=s[p]) {
                        T[p]=2;
                        if (1>T1[p]) {
                            T1[p]=1;
                        } else if (1>T2[p]) {
                            T2[p]=1;
                        }
                    }
                }
                count[p]--;
                if (!count[p]) {
                    q.push(p);
                }
                ans=max(ans, T1[p]+T2[p]+1);
            }
        }
        while (q.size()>0) {
            int curr=q.front();
            q.pop();
            int p = parent[curr];
            count[p]--;
            if (p>=0) {
                if (count[p]==0) {
                    q.push(p);
                }
                T[p]=max(T[p], s[curr]!=s[p] ? T[curr]+1 : 1);
                if (s[curr]!=s[p]) {
                    if (T[curr]>T1[p]) {
                        T2[p]=T1[p];
                        T1[p]=T[curr];
                    } else if (T[curr]>T2[p]) {
                        T2[p]=T[curr];
                    }
                }
                ans=max(ans, T1[p]+T2[p]+1);
            }
        }
        return ans;
    }
};