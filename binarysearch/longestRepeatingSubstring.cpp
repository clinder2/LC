class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int l=0;
        int r = s.length();
        int ans=0;
        while (l<=r) {
            int m = (l+r)/2;
            unordered_map<string,int> seen;
            bool good=false;
            for (int j = 0; j<=s.length()-m; j++) {
                string curr=s.substr(j, m);
                seen[curr]++;
                if (seen[curr]>1) {
                    ans=m;
                    l=m+1;
                    good=true;
                    break;
                }
            }
            if (!good) {
                r=m-1;
            }
        }
        return ans;
    }
};