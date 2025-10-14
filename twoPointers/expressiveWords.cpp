class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<int> freq;
        char prev=s[0];
        int temp=0;
        string a="";
        for (auto c : s) {
            if (c==prev) {
                temp+=1;
            } else {
                a+=prev;
                freq.push_back(temp);
                temp=1;
                prev=c;
            }
        }
        a+=prev;
        freq.push_back(temp);
        int ans=0;
        for (auto w : words) {
            int index=0;
            int i = 0;
            bool good=true;
            while (good && i<w.length()) {
                //cout<<i<<", "<<index<<"\n";
                if (index>=a.length()) {
                    good=false;
                    break;
                }
                if (w[i]!=a[index]) {
                    i=w.length();
                    good=false;
                    break;
                } else {
                    temp=0;
                    while (i<w.length() && w[i]==a[index]) {
                        i+=1;
                        temp++;
                    }
                    if (temp>freq[index] || (temp<freq[index] && freq[index]<3)) {
                        i=w.length();
                        good=false;
                        break;
                    }
                    index++;
                }
            }
            if (index!=a.length()) {
                good=false;
            }
            if (good) {
                ans++;
            }
        }
        return ans;
    }
};