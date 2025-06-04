class Solution {
public:
    int kthGrammar(int n, int k) {
        k--;
        int k2 = k;
        deque<int> temp;
        while (n>0 && k2>=1) {
            if (k2%2==1) {
                temp.push_front(1);
            } else {
                temp.push_front(0);
            }
            k2/=2;
            n--;
        }
        //cout<<temp.size();
        int prev = 0;
        for (auto i : temp) {
            if (i) {
                if (prev==0) {
                    prev = 1;
                } else {
                    prev=0;
                }
            } else {
                if (prev==0) {
                    prev = 0;
                } else {
                    prev=1;
                }
            }
        }
        return prev;
    }
};