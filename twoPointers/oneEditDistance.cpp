#include <vector>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length()+1!=t.length() && s.length()-1!=t.length() && s.length()!=t.length()) {
            return false;
        }
        if (t.length()==0 && s.length()==1) {
            return true;
        }
        if (t.length()==0 && s.length()==0) {
            return false;
        }
        int st =0;
        int l=s.length()-1;
        int l2=t.length()-1;
        while (st<min(s.length(),t.length()) && s[st]==t[st]) {
            st++;
        }
        while (l>=0 && l2>=0 && s[l]==t[l2]) {
            l--;
            l2--;
        }
        if (l2==-1 && st==0 || (l2==st-1) || (st==s.length() && l2==0)) {
            return true;
        }
        if (l==st+1 && s[st]!=t[l2]) {
            return false;
        }
        return st==l2;
    }
};