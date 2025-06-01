class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int prev=arr[0];
        vector<int> temp;
        int c = 0;
        for (auto i : arr) {
            if (i!=prev) {
                temp.push_back(c);
                prev=i;
                c=1;
            } else {
                c++;
            }
        }
        temp.push_back(c);
        sort(temp.begin(),temp.end());
        c = 0;
        for (auto i : temp) {
            //cout<<i<<"\n";
            if (k>=i) {
                k-=i;
                c++;
            } else {
                //cout<<temp.size();
                return temp.size()-c;
            }
        }
        return temp.size()-c;
    }
};