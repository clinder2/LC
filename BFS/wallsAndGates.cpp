#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int> >& rooms) {
        deque<vector<int> > temp;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j]==0) {
                    vector<int> a = {i, j};
                    temp.push_back(a);
                }
            }
        }
        long INF = 2147483647;
        vector<vector<int>> di = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while (temp.size()>0) {
            vector<int> curr = temp.front();
            temp.pop_front();
            if (rooms[curr[0]][curr[1]]>=0) {
                for (auto v : di) {
                    vector<int> a = curr;
                    a[0]+=v[0];
                    a[1]+=v[1];
                    if (a[0]>=0 && a[0]<rooms.size() && a[1]>=0 && a[1]<rooms[0].size() && rooms[a[0]][a[1]]==INF) {
                        rooms[a[0]][a[1]] = rooms[curr[0]][curr[1]]+1;
                        temp.push_back(a);
                    }
                }
            }
        }
    }
};