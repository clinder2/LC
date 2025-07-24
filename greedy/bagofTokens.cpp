class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        if (tokens.size()==0 || power<tokens[0]) {
            return 0;
        } else if (tokens.size()==1 && tokens[0]<=power) {
            return 1;
        }
        int ans = 0;
        int l = 0;
        while (l<tokens.size() && power-tokens[l]>0) {
            power-=tokens[l];
            l++;
            ans++;
        }
        int m = ans;
        vector<int> T(tokens.size());
        for (int i = l; i < tokens.size(); i++) {
            T[i] = T[max(0,i-1)]+tokens[i];
        }
        int r = tokens.size()-1;
        //cout<<l<<", "<<ans<<"\n";
        while (r>l) {
            power+=tokens[r];
            //cout<<power<<", "<<ans<<"\n";
            ans--;
            int r1=r, l1=l, m1=0, curr=0, old=0;
            while (r1>l1) {
                m1=(r1+l1)/2;
                //cout<<m<<", "<<r1<<", "<<l1<<", "<<curr<<"\n";
                if (T[m1]>power) {
                    r1=m1-1;
                } else {
                    curr=max(curr,m1-l1+1);
                    old=m1;
                    l1=m1+1;
                }
            }
            //cout<<T[r1]<<"r1\n";
            if (T[r1]<=power) {
                m1=r1;
                curr=max(curr,m1-l+1);
                //curr++;
                old=m1;
            }
            //cout<<m1<<", "<<r1<<", "<<l1<<", "<<curr<<", "<<power<<" this\n";
            ans+=curr;
            //power-=T[m1];
            m=max(m,ans);
            l+=curr;
            //cout<<m<<", "<<curr<<" curr\n";
            r--;
        }
        return m;
    }
};