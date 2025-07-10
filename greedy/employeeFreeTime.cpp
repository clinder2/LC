/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

struct CustomComparator {
        bool operator()(pair<Interval, pair<int,int>> a, pair<Interval, pair<int,int>> b) const {
            return a.first.start > b.first.start; 
        }
    };

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<pair<Interval, pair<int,int>>, vector<pair<Interval, pair<int,int>>>, CustomComparator> pq;
        int j=0;
        for (auto i : schedule) {
            //cout<<(i.front().start)<<"\n";
            pq.push(make_pair(i.front(), make_pair(j++, 0)));
        }
        vector<Interval> ans;
        pair<Interval, pair<int,int>> temp=pq.top();
        int prev = pq.top().first.end;
        //cout<<prev<<"\n";
        pq.pop();
        pq.push(make_pair(schedule[temp.second.first][temp.second.second+1], make_pair(temp.second.first, temp.second.second+1)));
        while (pq.size()>0) {
            pair<Interval, pair<int,int>> curr=pq.top();
            pq.pop();
            //cout<<curr.second.first<<"\n";
            if (curr.first.start>prev) {
                ans.push_back(*(new Interval(prev, curr.first.start)));
            }
            prev=max(prev, curr.first.end);
            if (curr.second.second+1<schedule[curr.second.first].size()) {
                pq.push(make_pair(schedule[curr.second.first][curr.second.second+1], make_pair(curr.second.first, curr.second.second+1)));
            }
        }
        return ans;
    }
};