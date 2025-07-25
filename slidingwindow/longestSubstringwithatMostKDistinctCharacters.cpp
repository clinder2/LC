class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k==0) {
            return 0;
        }
        map<char, int> seen;
        for (auto c : s) {
            seen[c]=0;
        }
        int l = 0; 
        int r = 0;
        int curr=0;
        int ans=0;
        while (r<s.length()) {
            if (seen[s[r]]==0) {
                curr++;
            }
            seen[s[r]]++;
            if (curr>k) {
                seen[s[l]]--;
                if (seen[s[l++]]==0) {
                    curr--;
                }
            }
            if (curr<=k) {
                ans=max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};