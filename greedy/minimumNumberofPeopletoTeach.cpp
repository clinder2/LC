class Solution {
public:
    bool common(vector<int> a, vector<int> b) {
        int i=0;
        int j = 0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while (i<a.size() && j<b.size()) {
            if (a[i]==b[j]) {
                return true;
            }
            if (a[i]<b[j]) {
                i++;
            } else {
                j++;
            }
        }
        while (i<a.size()) {
            if (a[i]==b.back()) {
                return true;
            }
            i++;
        }
        while (j<b.size()) {
            if (b[j]==a.back()) {
                return true;
            }
            j++;
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int, int> m;
        unordered_map<int,int> seen;
        int total=0;
        int ma=0;
        for (auto f : friendships) {
            if (!common(languages[f[0]-1], languages[f[1]-1])) {
                //cout<<f[0]<<", "<<f[1]<<"\n";
                if (!seen[f[0]-1]) {
                    total++;
                    seen[f[0]-1]=1;
                    for (auto i : languages[f[0]-1]) {
                        m[i]++;
                        ma=max(ma,m[i]);
                    }
                }
                if (!seen[f[1]-1]) {
                    total++;
                    seen[f[1]-1]=1;
                    for (auto i : languages[f[1]-1]) {
                        m[i]++;
                        ma=max(ma,m[i]);
                    }
                }
            }
        }
        return total-ma;
    }
};