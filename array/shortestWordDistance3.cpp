class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int i = -1;
        int j = -1;
        int ans = wordsDict.size();
        int k = 0;
        for (auto s : wordsDict) {
            if (s==word1) {
                i = k;
                if (j!=-1) {
                    ans=min(ans, i-j);
                }
            }
            if (s==word2) {
                j = k;
                if (i!=-1 && i!=j) {
                    ans=min(ans, j-i);
                }
            }
            k++;
        }
        return ans;
    }
};