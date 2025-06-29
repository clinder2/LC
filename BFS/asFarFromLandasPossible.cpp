class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        deque<pair<int,int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j]) {
                    q.push_back(make_pair(i, j));
                }
            }
        }
        int n = grid.size();
        int m = -1;
        if (q.size()==n*n || q.size()==0) {
            return -1;
        }
        int start = q.size();
        while (q.size()>0) {
            pair<int,int> curr=q.front();
            q.pop_front();
            int c = grid[curr.first][curr.second];
            if (start>0) {
                c--;
                start--;
            }
            if (c==0) {
                grid[curr.first][curr.second]=1;
            }
            if (curr.first+1<n && grid[curr.first+1][curr.second]==0) {
                grid[curr.first+1][curr.second]=c+1;
                m=max(m,c+1);
                q.push_back(make_pair(curr.first+1,curr.second));
            }
            if (curr.first-1>=0 && grid[curr.first-1][curr.second]==0) {
                grid[curr.first-1][curr.second]=c+1;
                m=max(m,c+1);
                q.push_back(make_pair(curr.first-1,curr.second));
            }
            if (curr.second+1<n && grid[curr.first][curr.second+1]==0) {
                grid[curr.first][curr.second+1]=c+1;
                m=max(m,c+1);
                q.push_back(make_pair(curr.first,curr.second+1));
            }
            if (curr.second-1>=0 && grid[curr.first][curr.second-1]==0) {
                grid[curr.first][curr.second-1]=c+1;
                m=max(m,c+1);
                q.push_back(make_pair(curr.first,curr.second-1));
            }
        }
        return m;
    }
};