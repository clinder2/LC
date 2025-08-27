class Solution {
public:
    int waysToDistribute(int n, int k) {
        vector<vector<long long>> T(k, *(new vector<long long>(n)));
        for (int i = 0; i < k; i++) {
            T[i][i]=1;
        }
        for (int i = 0; i < n; i++) {
            T[0][i]=1;
        }
        for (int i = 1; i < k; i++) {
            for (int j = i+1; j < n; j++) {
                T[i][j]=((T[i][j-1]*(i+1))%1000000007+T[i-1][j-1]%1000000007)%1000000007;
                T[i][j]%=1000000007;
            }
        }
        return T[k-1][n-1]%1000000007;
    }
};