#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int left = 0x7fffffff;
        int right = 0x8fffffff;
        unordered_map<double,unordered_map<double,int>> m;
        for (auto t : points) {
            if (t[0]<left) {
                left=t[0];
            }
            if (t[0]>right) {
                right=t[0];
            }
            if (m.find(t[0])==m.end()) {
                m[t[0]]=*(new unordered_map<double,int>());
            }
            m[t[0]][t[1]]=1;
        }
        double diff = right-left;
        double mid = left + (diff/2);
        int count = 0;
        int m2 = 2*(int)(m.size()/2)+1;
        for (auto p : points) {
            if (count<m2 && p[0]!=mid) {
                count++;
                double a=0;
                if (p[0]>mid) {
                    a=2*abs(mid-p[0]);
                } else {
                    a=-2*abs(mid-p[0]);
                }
                if (m.find(p[0]-a)==m.end() || m[p[0]-a].find(p[1])==m[p[0]].end()) {
                    return false;
                }
            }
        }
        return true;
    }
};