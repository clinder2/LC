class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> temp;
        temp.push_back(*(new vector<int>(26)));
        temp[0][s[0]-'a']++;
        for (int i = 1; i < s.length(); i++) {
            temp.push_back(temp.back());
            temp[i][s[i]-'a']++;
        }
        vector<bool> ans(queries.size());
        int index=0;
        for (auto q : queries) {
            vector<int> curr=temp[q[1]];
            if (q[0]>0) {
                for (int j = 0; j < 26; j++) {
                    curr[j]-=temp[q[0]-1][j];
                }
            }
            int bad=0;
            for (auto i : curr) {
                bad+=i%2;
            }
            bad=floor(bad/2);
            ans[index]=bad<=q[2] ? true : false;
            index++;
        }
        return ans;
    }
};