#include <vector>

class Solution {
public:
    vector<vector<int>> ans = *(new vector<vector<int>>());
    vector<vector<int>> combinationSum3(int k, int n) {
        back(k, n, *(new vector<int>()));
        return ans;
    }
    void back(int k, int n, vector<int> a) {
        if (a.size()==k) {
            if (accumulate(a.begin(), a.end(), 0)==n) {
                ans.push_back(a);
            }
        } else {
            int b;
            if (a.size()==0) {
                b=0;
            } else {
                b=a.back();
            }
            for (int i = b+1; i < 10; i++) {
                a.push_back(i);
                back(k, n, a);
                a.pop_back();
            }
        }
    }
};