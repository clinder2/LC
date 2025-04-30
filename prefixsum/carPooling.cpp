#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> t(1001);
        for (auto tr : trips) {
            t[tr[1]]+=tr[0];
            t[tr[2]]+=-tr[0];
        }
        int ans=0;
        for (int i = 0; i < t.size(); i++) {
            ans+=t[i];
            if (ans > capacity) {
                return false;
            }
        }
        return true;
    }
};