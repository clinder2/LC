class Solution {
public:
    string reorganizeString(string s) {
        vector<int> c(26,0);
        for (auto ch : s) {
            c[ch-'a']++;
        }
        priority_queue<pair<int, char>> pq;
        int index = -1;
        for (int i = 0; i < 26; i++) {
            if (c[i]) {
                index++;
                //cout<<(char)('a'+i)<<"\n";
                pq.push(make_pair(c[i], (char)('a'+i)));
            }
        }
        string st = "";
        pair<int, char> prev = pq.top();
        pq.pop();
        st+=prev.second;
        prev.first=prev.first-1;
        while (pq.size()>0) {
            pair<int, char> curr = pq.top();
            pq.pop();
            curr.first=curr.first-1;
            st+=curr.second;
            if (prev.first>0) {
                pq.push(prev);
            }
            prev=curr;
        }
        if (prev.first>0) {
            return "";
        }
        return st;
    }
};