#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k==weights.size()) {
            return 0;
        }
        priority_queue<pair<int,int> > h;
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > mh;
        for (int i = 1; i < weights.size();i++) {
            h.push({weights[i-1]+weights[i], i});
            mh.push({weights[i-1]+weights[i], i});
        }
        vector<int> ind;
        vector<int> ind2;
        k--;
        while (h.size()>0 && k>0) {
            ind.push_back(h.top().second);
            ind2.push_back(mh.top().second);
            h.pop();
            mh.pop();
            k--;
        }
        sort(ind.begin(),ind.end());
        sort(ind2.begin(),ind2.end());
        int prev=0;
        long ans=0;
        long ans2=0;
        for (auto i : ind) {
            ans+=weights[prev]+weights[i-1];
            prev=i;
            //cout<<i<<", "<<prev<<"\n";
        }
        ans+=weights[weights.size()-1]+weights[prev];
        prev=0;
        for (auto i : ind2) {
            ans2+=weights[prev]+weights[i-1];
            prev=i;
            //cout<<i<<", "<<prev<<"\n";
        }
        ans2+=weights[weights.size()-1]+weights[prev];
        return ans-ans2;
    }
};