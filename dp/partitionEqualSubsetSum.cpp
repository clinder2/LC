#include <vector>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = accumulate(nums.begin(), nums.end(), 0);
        if (n%2==1) {
            return false;
        }
        n=(int)n/2;
        vector<vector<int>> T(n+1, vector<int>(nums.size()+1, 0));
        for (int i = 0; i < nums.size(); i++) {
            T[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= nums.size(); j++) {
                if (nums[j-1] <= i) {
                    T[i][j] = max(T[i][j-1], T[i-nums[j-1]][j-1]);
                } else {
                    T[i][j] = T[i][j-1];
                }
            }
        }
        return T[n][nums.size()];
    }
};