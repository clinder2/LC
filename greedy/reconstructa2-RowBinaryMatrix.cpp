class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> A(2,*(new vector<int>(colsum.size())));
        vector<vector<int>> A2;
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i]==2) {
                A[0][i]=1;
                A[1][i]=1;
                upper--;
                lower--;
            }
        }
        if (upper<0 || lower<0) {
            return A2;
        }
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i]==1) {
                if (upper>0) {
                    A[0][i]=1;
                    upper--;
                } else if (lower>0) {
                    A[1][i]=1;
                    lower--;
                } else {
                    return A2;
                }
            }
        }
        if (upper>0 || lower>0) {
            return A2;
        }
        return A;
    }
};