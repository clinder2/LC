class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (query_row==0) {
            return poured>0 ? (poured > 1 ? 1 : poured) : 0;
        }
        vector<vector<double>> T(100,*(new vector<double>(100)));
        T[0][0]=poured-1;
        for (int i = 1; i < query_row; i++) {
            T[i][0]=(.5*T[i-1][0] > 0) ? .5*T[i-1][0] : 0;
            /* if (.5*T[i-1][0]>1) {
                T[i][0]--;
            } */
            T[i][0]--;
            //cout<<T[i][0]<<", ";
            for (int j = 1; j < i; j++) {
                T[i][j]=(T[i-1][j-1]/2>0 ? T[i-1][j-1]/2 : 0) + (T[i-1][j]/2>0 ? T[i-1][j]/2 : 0);
                T[i][j]--;
                //cout<<T[i][j]<<", ";
            }
            T[i][i]=(.5*T[i-1][i-1])>0 ? .5*T[i-1][i-1] : 0;
            T[i][i]--;
            //cout<<T[i][i]<<"\n";
        }
        int i = query_row;
        int j = query_glass;
        if (query_glass==0) {
            double curr = T[i-1][0]/2 > 0 ? T[i-1][0]/2 : 0;
            if (curr>1) {
                return 1;
            }
            return curr;
        }
        double curr= (T[i-1][j-1]/2>0 ? T[i-1][j-1]/2 : 0) + (T[i-1][j]/2>0 ? T[i-1][j]/2 : 0);
        return curr>1 ? 1 : curr;
    }
};