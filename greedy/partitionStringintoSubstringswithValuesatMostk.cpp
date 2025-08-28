class Solution {
public:
    int minimumPartition(string s, int k) {
        int index=0;
        int ans=0;
        while (index<s.length()) {
            int j=index;
            while (j<s.length() && stol(s.substr(index, j-index+1))<=k) {
                j++;
            }
            if (j==index) {
                return -1;
            }
            index=j;
            ans++;
        }
        return ans;
    }
};