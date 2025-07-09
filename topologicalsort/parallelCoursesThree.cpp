class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> T(n+1, *(new vector<int>()));
        vector<int> indeg(n+1,0);
        int m=0;
        for (auto i : relations) {
            T[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }
        vector<int> t(n+1,0);
        deque<int> q;
        for (int i = 1; i <= n; i++) {
            t[i]=time[i-1];
            m=max(m,time[i-1]);
            if (!indeg[i]) {
                q.push_back(i);
            }
        }
        int ans=m;
        while (q.size()>0) {
            int curr = q.front();
            q.pop_front();
            for (auto i : T[curr]) {
                t[i]=max(t[i], time[i-1]+t[curr]);
                ans=max(ans,t[i]);
                indeg[i]--;
                if (!indeg[i]) {
                    q.push_back(i);
                }
            }
        }
        return ans;
    }
};