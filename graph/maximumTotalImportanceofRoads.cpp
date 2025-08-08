class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> count(n);
        for (auto p : roads) {
            count[p[0]]++;
            count[p[1]]++;
        }
        sort(count.begin(), count.end());
        long long ans=0;
        for (int i = 0; i<n; i++) {
            //cout<<count[n-i]<<"\n";
            ans+=(long long) (i+1)*count[i];
        }
        return ans;
    }
};