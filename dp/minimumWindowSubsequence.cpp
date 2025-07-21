class Solution {
public:
    string minWindow(string s1, string s2) {
        vector<vector<int>> T(s2.length()+1, *(new vector<int>(s1.length()+1)));
        for (int i = 0; i <= s1.length(); i++) {
            T[0][i]=1;
        }
        string ans=s1;
        bool good=0;
        for (int i = 1; i <= s2.length(); i++) {
            for (int j = 1; j <= s1.length(); j++) {
                //cout<<i<<", "<<j<<"\n";
                if (s1[j-1]==s2[i-1] && T[i-1][j-1]) {
                    T[i][j]=2;
                } else if (s1[j-1]==s2[i-1]) {
                    T[i][j]=min(1,T[i][j-1]);
                } else {
                    T[i][j]=min(1,T[i][j-1]);
                }
                //cout<<T[i][j]<<" ";
                if (T[i][j]==2 && i==s2.length()) {
                    //cout<<i<<", "<<j<<"\n";
                    int oldi=i;
                    int oldj = j;
                    good=1;
                    int end = j;
                    j--;
                    i--;
                    while (i>0) {
                        while (j>0 && T[i][j]!=2) {
                            j--;
                        }
                        i--;
                        j--;
                    }
                    string temp = s1.substr(j,end-j);
                    //cout<<j<<", "<<end<<"\n";
                    if (ans.length()>temp.length()) {
                        ans=temp;
                    }
                    i=oldi;
                    j=oldj;
                    //return s1.substr(j,end-j);
                }
            }
            //cout<<"\n";
        }
        if (good) {
            return ans;
        }
        return "";
    }
};