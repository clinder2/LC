class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        vector<vector<long long>> T(2, vector<long long>(regular.size()+1, 0));
        T[0][1] = min(regular[0], expressCost+express[0]);
        T[1][1] = expressCost+express[0];
        for (int i = 2; i < T[0].size(); i++) {
            T[0][i]=min(T[0][i-1], T[1][i-1])+regular[i-1];
            T[1][i]=min(T[1][i-1], T[0][i-1]+expressCost)+express[i-1];
        }
        vector<long long> ans;
        for (int i = 1; i < T[0].size(); i++) {
            ans.push_back(min(T[0][i], T[1][i]));
        }
        return ans;
    }
};