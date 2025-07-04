class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) {
            vector<int> a;
            a.push_back(0);
            return a;
        } else if (n==2) {
            vector<int> a;
            a.push_back(0);
            a.push_back(1);
            return a;
        }
        vector<int> nodes(n);
        unordered_map<int,vector<int>> m;
        for (int i = 0; i<n; i++) {
            m[i] = *(new vector<int>());
        }
        int s = 0;
        for (auto e : edges) {
            nodes[e[0]]++;
            nodes[e[1]]++;
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
            s+=2;
        }
        deque<int> q;
        for (int i = 0; i < n; i++) {
            if (nodes[i]==1) {
                q.push_back(i);
            }
        }
        int prev=q.size();
        int next=0;
        while (prev>0) {
            int curr=q.front();
            q.pop_front();
            prev--;
            nodes[curr]--;
            for (auto i : m[curr]) {
                if (nodes[i]>0) {
                    nodes[i]--;
                    if (nodes[i]==1) {
                        q.push_back(i);
                        next++;
                    }
                }
            }
            s-=2;
            if (prev==0) {
                prev=next;
                if (s<=2) {
                    prev=0;
                }
                next=0;
            }
        }
        vector<int> ans;
        for (auto i : q) {
            ans.push_back(i);
        }
        return ans;
    }
};