class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        vector<vector<double>> T(dist.size()+1, *(new vector<double>(dist.size()+1)));
        int temp=0;
        int ans=0;
        for (int i = 1; i <= dist.size(); i++) {
            temp+=ceil((double)dist[i-1]/speed - 0.00000001);
            T[0][i]=temp;
            T[i][1]=(double)dist[0]/speed;
        }
        if (temp<=hoursBefore) {
            return 0;
        }
        for (int i = 1; i < T.size(); i++) {
            for (int j = 2; j < T[0].size(); j++) {
                double temp1 = min(((double)dist[j-1]/speed)+T[i-1][j-1], (double)ceil(((double)dist[j-1]/speed)+T[i][j-1]- 0.00000001));
                T[i][j]=temp1;
                if (j==T[0].size()-1 && T[i][j]<=hoursBefore) {
                    return i;
                }
            }
        }
        return -1;
    }
};