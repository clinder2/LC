class Solution {
public:
    vector<int> T;
    vector<int> l;
    int n;
    int ans=(1024*1024)-1;
    int t;
    string minAbbreviation(string target, vector<string>& dictionary) {
        //vector<int> l;
        //printf("%b ", ans);
        int index=0;
        n=target.length();
        T = *(new vector<int>(1<<(target.size()), 0));
        vector<string> d;
        for (auto s : dictionary) {
            if (s.length()==target.length()) {
                d.push_back(s);
            }
        }
        dictionary=d;
        for (auto s : dictionary) {
            if (s.length()==target.length()) {
                int curr=0;
                for (int i = 0; i<s.length(); i++) {
                    if (s[i]!=target[i]) {
                        //cout<<s.length()-i-1<<", ";
                        curr|=(1<<(s.length()-i-1));
                    }
                }
                //printf("%b , ", curr);
                l.push_back(curr);
            }
            index++;
        }
        int state = dfs(0, 0);
        state=ans;
        //printf(" state %b", state);
        int count=0;
        string a="";
        int i = 0;
        while (i < n) {
            while (i<n && !(state&(1<<i))) {
                i++;
                count++;
            }
            if (count>0) {
                a=to_string(count)+a;
            }
            count=0;
            while (i<n && (state&(1<<i))) {
                //i++;
                a=target[n-1-i++]+a;
            }
            //cout<<i<<", ";
        }
        return a;
    }
    int len(int a) {
        int count=0;
        //printf(" %b a, ", a);
        int i = 0;
        while (i < n) {
            while (i<n && !(a&(1<<i))) {
                i++;
            }
            if (i>0) {
                count++;
            }
            //cout<<i<<", "<<count<<"\n";
            while (i<n && (a&(1<<i))) {
                i++;
                count++;
            }
        }
        return count;
    }
    int dfs(int curr, int index) {
        if (index==l.size()) {
            if (len(curr)<T[curr] && T[curr]) {
                T[curr]=len(curr);
                if (len(curr)<len(ans)) {
                    ans=curr;
                }
            } else if (!T[curr]) {
                T[curr]=len(curr);
                if (len(curr)<len(ans)) {
                    ans=curr;
                }
            }
            //printf(" c %b l %d a %b", curr, len(curr), ans);
            //cout<<T[curr]<<"\n";
            return T[curr];
        }
        if (T[curr]) {
            return T[curr];
        }
        int temp=30;
        for (int i = 0; i < n; i++) {
            if (l[index]&(1<<(n-i-1))) {
                int curr2=curr|(1<<(n-i-1));
                //printf(" %b, ", curr2);
                temp=min(temp,dfs(curr2, index+1));
                //cout<<temp<<"t, ";
            }
        }
        //cout<<ans<<" ans\n";
        T[curr]=temp;
        return temp;
    }
};