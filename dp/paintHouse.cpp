#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int> >& costs) {
        vector<vector<int> > T(costs.size(), vector<int>(3,0));
        T[0][0]=costs[0][0];
        T[0][1]=costs[0][1];
        T[0][2]=costs[0][2];
        for (int i = 1; i < costs.size(); i++) {
            for (int j = 0; j < 3; j++) {
                T[i][j]=costs[i][j]+min(T[i-1][(j+1)%3], T[i-1][(j+2)%3]);
            }
        }
        return min(T[costs.size()-1][0], min(T[costs.size()-1][1],T[costs.size()-1][2]));
    }
};