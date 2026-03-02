class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n=flights.size();
        int k=days[0].size();
        vector<vector<int>> T(days.size(), *(new vector<int>(days[0].size())));
        T[0][0]=days[0][0];
        map<int,vector<int>> m;
        for (int i = 1; i < n; i++) {
            if (flights[0][i]) {
                T[i][0]=days[i][0];
                m[i].push_back(0);
            }
            for (int j = 0; j < n; j++) {
                if (flights[i][j]) {
                    m[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            m[i].push_back(i);
        }
        for (int j = 1; j < k; j++) {
            for (int i = 0; i < n; i++) {
                T[i][j]=days[i][j];
                int temp=0;
                for (auto a : m[i]) {
                    temp=max(temp,T[a][j-1]);
                }
                if (!temp) {
                    if (!T[i][j-1] && i!=0) {
                        T[i][j]=0;
                        temp=0;
                    } else {
                        temp=days[i][j];
                        T[i][j]=T[i][j-1];
                    }
                }
                T[i][j]+=temp;
            }
        }
        int ans=0;
        for (int i = 0; i < n; i++) {
            ans=max(ans,T[i][k-1]);
        }
        return ans;
    }
};