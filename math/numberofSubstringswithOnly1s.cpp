class Solution {
public:
    int numSub(string s) {
        vector<int> temp;
        int length=0;
        bool prev=false;
        for (auto c : s) {
            if (c=='1') {
                if (prev) {
                } else {
                    prev=true;
                }
                length++;
            } else {
                prev=false;
                if (length) {
                    temp.push_back(length);
                }
                length=0;
            }
        }
        if (length) {
            temp.push_back(length);
        }
        long long curr=1;
        for (auto i : temp) {
            //cout<<i<<" ";
            long long t=i;
            t*=(i+1);
            curr+=((t)/2)%1000000007;
        }
        return (int)(curr-1)%1000000007;
    }
};