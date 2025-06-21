class Compare {
public:
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[0]>b[0];
    }
};
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>, vector<vector<int>>, Compare> sell;
        long total=0;
        long total2=0;
        for (auto t : orders) {
            //total2%=1000000007;
            total2+=t[1];
            if (t[2]) {
                while (buy.size()>0 && buy.top()[0]>=t[0] && t[1]>=buy.top()[1]) {
                    //total%=1000000007;
                    total+=2*buy.top()[1];
                    t[1]-=buy.top()[1];
                    buy.pop();
                }
                if (buy.size()>0 && buy.top()[0]>=t[0] && t[1]>0) {
                    //total%=1000000007;
                    total+=(2*t[1]);
                    vector<int> temp = buy.top();
                    buy.pop();
                    temp[1]-=t[1];
                    buy.push(temp);
                    t[1]=0;
                }
                if (t[1]>0) {
                    sell.push(t);
                }
            } else {
                //cout<<t[0]<<" b\n";
                while (sell.size()>0 && sell.top()[0]<=t[0] && t[1]>=sell.top()[1]) {
                    //total%=1000000007;
                    total+=(2*sell.top()[1]);
                    t[1]-=sell.top()[1];
                    //cout<<sell.top()[0]<<" b\n";
                    sell.pop();
                }
                //cout<<sell.size()<<" a\n";
                if (sell.size()>0 && sell.top()[0]<=t[0] && t[1]>0) {
                    //total%=1000000007;
                    total+=(2*t[1]);
                    vector<int> temp = sell.top();
                    sell.pop();
                    temp[1]-=t[1];
                    sell.push(temp);
                    t[1]=0;
                    //cout<<total<<" a\n";
                }
                if (t[1]>0) {
                    buy.push(t);
                }
            }
        }
        return (total2-total)%1000000007;
    }
};