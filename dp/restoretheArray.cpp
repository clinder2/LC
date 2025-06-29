class Solution {
public:
    int numberOfArrays(string s, int k) {
        vector<int> T(s.length()+1,0);
        T[0]=1;
        string str = to_string(k);
        int n = str.length();
        for (int i = 1; i < T.size(); i++) {
            int st = i-1;
            while (st>=0 && s[st]=='0') {
                if (i-st>n) {
                    st=-1;
                }
                st--;
            }
            int ans=0;
            //cout<<st<<", "<<i<<", "<<s.substr(0,i)<<"b\n";
            while (st>=0 && stoll(s.substr(st,i-st))<=k) {
                if (s[st]!='0') {
                    ans%=1000000007;
                    ans+=T[st]%1000000007;
                }
                st--;
                //cout<<st<<", "<<i-st<<", "<<"s\n";
            }
            T[i]=ans%1000000007;
            //cout<<ans<<"a\n";
        }
        return T.back()%1000000007;
    }
};