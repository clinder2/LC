class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> firstu(26,-1);
        vector<int> lastl(26,-1);
        for (int i = 0; i < word.length(); i++) {
            if (word[i]-'a'>=0 && word[i]-'a'<=26) {
                lastl[word[i]-'a']=i;
            } else if (firstu[word[i]-'A']<0) {
                firstu[word[i]-'A']=i;
            }
        }
        int ans=0;
        for (int i = 0; i < 26; i++) {
            if (firstu[65+i-'A']>=0 && lastl[97+i-'a']>=0 && firstu[65+i-'A']>lastl[97+i-'a']) {
                ans++;
            }
        }
        return ans;
    }
};