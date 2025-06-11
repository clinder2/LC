class Solution {
public:
    int shortestWay(string source, string target) {
        vector<vector<int> > T(target.size()+1, vector<int>(source.size()+1,0));
        for (int i = 0; i < T[0].size(); i++) {
           T[0][i]=1;
        }
        int prev = source.size()+1;
        int ans = 0;
        for (int i = 1; i<=target.size(); i++) {
            prev=source.size()+1;
            bool good = false;
            for (int j = 1; j <= source.size(); j++) {
                if (source[j-1]==target[i-1]) {
                    prev = min(j-1,prev);
                    if (T[i-1][j-1]>0) {
                        good = true;
                        for (int k = j; k<T[0].size();k++) {
                            T[i][k]=1;
                        }
                        j=source.size()+1;
                    }
                }
            }
            if (prev==source.size()+1) {
                return -1;
            }
            if (!good) {
                for (int k = prev+1; k<T[0].size();k++) {
                    T[i][k]=1;
                }
                ans++;
            }
        }
        return ans+1;
    }
};