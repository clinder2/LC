class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> y={0,0,0};
        vector<int> ny={0,0,0};
        for (int i = 0; i < (int)n/2; i++) {
            //cout<<n-1-i<<" "<<n/2<<", ";
            int curr=grid[i][i];
            //cout<<curr<<"\n";
            grid[i][i]=-1;
            y[curr]++;
            curr=grid[i][n-1-i];
            //cout<<curr<<"\n";
            grid[i][n-1-i]=-1;
            y[curr]++;
            curr=grid[n-1-i][(n/2)];
            //cout<<curr<<"\n";
            grid[n-1-i][(n/2)]=-1;
            y[curr]++;
        }
        y[grid[(n/2)][(n/2)]]++;
        grid[(n/2)][(n/2)]=-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]>=0) {
                    ny[grid[i][j]]++;
                }
            }
        }
        //cout<<y[0]<<" "<<y[1]<<" "<<y[2]<<"\n";
        //cout<<ny[0]<<" "<<ny[1]<<" "<<ny[2]<<" ";
        int curr=y[0];
        int yin=0;
        if (y[1]>curr) {
            curr=y[1];
            yin=1;
        }
        if (y[2]>curr) {
            curr=y[2];
            yin=2;
        }
        int t1=y[(yin+1)%3]+y[(yin+2)%3];
        int currny=ny[(yin+1)%3]>ny[(yin+2)%3] ? (yin+1)%3 : (yin+2)%3;
        t1+=ny[(currny+1)%3]+ny[(currny+2)%3];
        curr=ny[0];
        yin=0;
        if (ny[1]>curr) {
            curr=ny[1];
            yin=1;
        }
        if (ny[2]>curr) {
            curr=ny[2];
            yin=2;
        }
        int t2=ny[(yin+1)%3]+ny[(yin+2)%3];
        int curry=y[(yin+1)%3]>y[(yin+2)%3] ? (yin+1)%3 : (yin+2)%3;
        t2+=y[(curry+1)%3]+y[(curry+2)%3];
        return min(t1,t2);
    }
};