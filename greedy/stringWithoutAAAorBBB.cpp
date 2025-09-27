class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        string f=a>b ? "a" : "b";
        string s=a<=b ? "a" : "b";
        int f1 = max(a,b);
        int s1 = min(a,b);
        int temp = max(1,(int)(ceil((double)f1/2)-1));
        int t1=s1-temp;
        int t2=2*temp-s1;
        if (a==b) {
            t1=(int)a/2;
            t2=-1;
        }
        for (int i = 0; i < t1; i++) {
            if (f1>=2) {
                ans+=f+f;
                f1-=2;
            } else if (f1==1) {
                ans+=f;
                f1--;
            }
            if (s1>=2) {
                ans+=s+s;
                s1-=2;
            } else if (s1==1) {
                ans+=s;
                s1--;
            }
        }
        for (int i = 0; i < t2; i++) {
            ans+=f+f+s;
            f1-=2;
            s1-=1;
        }
        for (int i = 0; i < f1; i++) {
            ans+=f;
        }
        for (int i = 0; i < s1; i++) {
            ans+=s;
        }
        return ans;
    }
};