class Solution {
public:
    int checkRecord(int n) {
        vector<vector<long long>> T(2, *(new vector<long long>(n)));
        T[0][0]=2;
        T[1][0]=1;
        if (n>=2) {
            T[0][1]=4;
            T[1][1]=4;
        }
        if (n>=3) {
            T[0][2]=7;
            T[1][2]=12;
        }
        for (int i = 3; i < n; i++) {
            T[0][i]=((T[0][i-1])+T[0][i-2]+(T[0][i-3]));
            T[1][i]=((T[0][i-1]+T[1][i-1])+T[1][i-2]+T[0][i-2]+T[1][i-3]+T[0][i-3]);
            T[0][i]%=1000000007;
            T[1][i]%=1000000007;
        }
        return (T[0].back()+T[1].back())%1000000007;
    }
};