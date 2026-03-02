class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        vector<vector<int>> T(arr.size(), *(new vector<int>(arr.size())));
        for (int i=0; i < arr.size(); i++) {
            T[i][i]=1;
        }
        for (int t=1; t<arr.size(); t++) {
            for (int i = 0; i < arr.size()-t; i++) {
                int j=t+i;
                    if (arr[i]==arr[j]) {
                        if (i==j-1) {
                            T[i][j]=1;
                        } else {
                            T[i][j]=T[i+1][j-1];
                        }
                    } 
                        int ans=10000;
                        for (int k = i; k<j; k++) {
                            ans=min(ans,T[i][k]+T[k+1][j]);
                        }
                    if (T[i][j]) {
                        T[i][j]=min(T[i][j],ans);
                    } else {
                        T[i][j]=ans;
                    }
            }
        }
        return T[0][arr.size()-1];
    }
};