class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        vector<vector<int>> T(costs.size(), *(new vector<int>(costs[0].size())));
        int prevmin1=100000, prevmin2=100000, min1=100000, min2 = 100000;
        for (int i = 0; i< T[0].size(); i++) {
            T[0][i]=costs[0][i];
            if (T[0][i]<prevmin1) {
                prevmin2=prevmin1;
                prevmin1=T[0][i];
            } else if (T[0][i]<prevmin2) {
                prevmin2=T[0][i];
            }
        }
        if (T.size()==1) {
            return prevmin1;
        }
        //cout<<prevmin1<<", "<<prevmin2<<"\n";
        for (int i = 1; i < T.size(); i++) {
            //cout<<prevmin1<<", "<<prevmin2<<"\n";
            for (int j = 0; j < T[0].size(); j++) {
                T[i][j]=costs[i][j];
                if (T[i-1][j]==prevmin1) {
                    //cout<<T[i][j]<<", "<<prevmin2<<" tt\n";
                    T[i][j]+=prevmin2;
                } else {
                    T[i][j]+=prevmin1;
                }
                if (T[i][j]<min1) {
                    min2=min1;
                    min1=T[i][j];
                } else if (T[i][j]<min2) {
                    min2=T[i][j];
                }
                //cout<<T[i][j]<<" ";
            }
            //cout<<"\n";
            prevmin1=min1;
            prevmin2=min2;
            min1=10000;
            min2=10000;
        }
        return prevmin1;
    }
};