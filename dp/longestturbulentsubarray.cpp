#include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size()==1) {
            return 1;
        }
        int a = 1;
        int a2=1;
        int t = 1;
        int t2=-1;
        int ans=0;
        for (int i = 1; i < arr.size(); i++) {
            if ((arr[i]-arr[i-1])*t>0) {
                a++;
                ans=max(ans,a);
            } else {
                a=1;
            }
            if ((arr[i]-arr[i-1])*t2>0) {
                a2++;
                ans=max(ans,a2);
            } else {
                a2=1;
            }
            t*=-1;
            t2*=-1;
        }
        return max(ans,1);
    }
};