class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;
        for (int i = 0; i < profits.size(); i++) {
            if (capital[i]<=w) {
                pq.push(make_pair(profits[i],capital[i]));
            } else {
                pq2.push(make_pair(capital[i],profits[i]));
            }
        }
        int ans=w;
        while (k && pq.size()) {
            pair<int,int> curr=pq.top();
            pq.pop();
            ans+=curr.first;
            //w+=curr.first-curr.second;
            w+=curr.first;
            k--;
            if (!k) {
                //ans+=w;
            } else {
                //ans+=curr.first;
            }
            while (pq2.size() && pq2.top().first<=w) {
                curr=pq2.top();
                pq.push(make_pair(curr.second,curr.first));
                pq2.pop();
            }
            //cout<<w;
        }
        return ans;
    }
};