#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int> >& grid) {
        if (grid[0][0]==1 || grid[grid.size()-1][grid[0].size()-1]==1) {
            return -1;
        }
        if (grid.size()==1) {
            return 1;
        }
        queue<vector<int> > q;
        vector<int> a = {0,0};
        q.push(a);
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (q.size()>0) {
            vector<int> curr = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                if (curr[0]+dr[i]>=0 && curr[0]+dr[i]<grid.size() && curr[1]+dc[i]>=0 && curr[1]+dc[i]<grid[0].size()) {
                    if (grid[curr[0]+dr[i]][curr[1]+dc[i]]==0) {
                        grid[curr[0]+dr[i]][curr[1]+dc[i]]=grid[curr[0]][curr[1]]+1;
                        vector<int> t = {curr[0]+dr[i], curr[1]+dc[i]};
                        q.push(t);
                    }
                }
            }
        }
        if (grid[grid.size()-1][grid[0].size()-1]==0) {
            return -1;
        } else {
            return grid[grid.size()-1][grid[0].size()-1]+1;
        }
    }
};