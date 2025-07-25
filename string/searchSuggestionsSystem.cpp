class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<int>> t(searchWord.length());
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.length(); i++) {
            t[i]=*(new vector<int>());
        }
        for (int i = 0; i < products.size(); i++) {
            string s = products[i];
            int e = -1;
            while (e+1<min(s.length(), searchWord.length())) {
                if (s[e+1]==searchWord[e+1]) {
                    e++;
                    t[e].push_back(i);
                } else { 
                    e=searchWord.length();
                }
            }
        }
        for (int i = 0; i < searchWord.length(); i++) {
            vector<string> temp;
            //int a = t[i].size();
            int a = t[i].size();
            a = min(3, a);
            for (int j = 0; j < a; j++) {
                //cout<<t[i][j]<<", "<<i<<"\n";
                temp.push_back(products[t[i][j]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};