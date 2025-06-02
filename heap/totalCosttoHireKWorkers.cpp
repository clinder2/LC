class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int l = candidates-1;
        int r = costs.size()-candidates;
        long long cost = 0;
        int c = candidates;
        if (2*candidates > costs.size()) {
            c = (int)costs.size()/2;
        }
        for (int i = 0; i < c; i++) {
            pq1.push(costs[i]);
            pq2.push(costs[costs.size()-1-i]);
        }
        if (c!=candidates && costs.size()%2==1) {
            pq1.push(costs[c]);
        }
        while (k>0 && l<r-1 && pq1.size()>0 && pq2.size()>0) {
            if (pq1.top()<=pq2.top()) {
                cost+=pq1.top();
                pq1.pop();
                pq1.push(costs[++l]);
            } else {
                cost+=pq2.top();
                pq2.pop();
                pq2.push(costs[--r]);
            }
            k--;
        }
        while (k>0 && pq1.size()>0 && pq2.size()>0) {
            if (pq1.top()<=pq2.top()) {
                cost+=pq1.top();
                pq1.pop();
            } else {
                cost+=pq2.top();
                pq2.pop();
            }
            k--;
        }
        while (k>0 && pq1.size()>0) {
            cost+=pq1.top();
            pq1.pop();
            k--;
        }
        while (k>0 && pq2.size()>0) {
            cost+=pq2.top();
            pq2.pop();
            k--;
        }
        return cost;
    }
};