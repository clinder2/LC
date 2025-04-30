#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int a = matrix.size();
        int b = matrix[0].size();
        vector<vector<int> > T(a, vector<int>(b,0));
        int ans=0;
        for (int i = 0; i < matrix.size(); i++) {
            T[i][0]=matrix[i][0]-'0';
            ans=max(ans,T[i][0]);
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            T[0][i]=matrix[0][i]-'0';
            ans=max(ans,T[0][i]);
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j]=='1') {
                    T[i][j]=min((int)T[i][j-1],min((int)T[i-1][j], (int)T[i-1][j-1]))+1;
                    ans=max(ans,(int)T[i][j]);
                }
            }
        }
        return ans*ans;
    }
};