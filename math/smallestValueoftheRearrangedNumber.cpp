class Solution {
public:
    long long smallestNumber(long long num) {
        if (!num) {
            return num;
        }
        priority_queue<int> pq2;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long temp=num;
        int z=0;
        long long t = 1;
        while (temp!=0) {
            //cout<<(temp%10)<<"\n";
            if (temp%10==0) {
                z++;
            } else {
                //cout<<(num>0)<<"\n";
                if (num>0) {
                    pq.push(temp%10);
                } else {
                    pq2.push(abs(temp%10));
                }
            }
            temp/=10;
            t*=10;
        }
        long long ans=0;
        t/=10;
        if (num>0) {
            ans+=t*pq.top();
            pq.pop();
            t/=10;
            if (z) {
                t/=pow(10, z);
            }
            while (pq.size()>0) {
                ans+=t*pq.top();
                pq.pop();
                t/=10;
            }
        } else {
            ans+=t*pq2.top();
            pq2.pop();
            t/=10;
            while (pq2.size()>0) {
                ans+=t*pq2.top();
                pq2.pop();
                t/=10;
            }
            ans*=-1;
        }
        return ans;
    }
};