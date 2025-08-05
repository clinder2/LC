class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        if (!k) {
            int a=0;
            for (auto i : reward2) {
                a+=i;
            }
            return a;
        }
        priority_queue<int> pq;
        int m=0;
        for (int i = 0; i < k; i++) {
            m+=reward1[i];
            pq.push(reward2[i]-reward1[i]);
        }
        int prev = m;
        for (int i = k; i < reward1.size(); i++) {
            int temp = prev+reward2[i];
            int temp2=prev+reward1[i]+pq.top();
            if (temp>temp2) {
                prev=temp;
            } else {
                prev=temp2;
                pq.pop();
                pq.push(reward2[i]-reward1[i]);
            }
        }
        return prev;
    }
};