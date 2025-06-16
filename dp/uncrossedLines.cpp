class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size()+1;
        int b = nums2.size()+1;
        vector<vector<int>> T(a, vector<int>(b, 0));
        for (int i = 1; i < T.size(); i++) {
            for (int j = 1; j < T[0].size(); j++) {
                if (nums1[i-1]==nums2[j-1]) {
                    //cout<<i<<", "<<j<<"\n";
                    T[i][j] = 1+T[i-1][j-1];
                    //cout<<T[i][j]<<"\n";
                } else {
                    //cout<<i<<", "<<j<<" a\n";
                    T[i][j] = max(T[i][j-1], max(T[i-1][j], T[i-1][j-1]));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < T.size(); i++) {
            ans=max(ans, T[i][T[0].size()-1]);
        }
        return ans;
    }
};