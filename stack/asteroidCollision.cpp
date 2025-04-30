#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i = 0;
        while (i<asteroids.size() && asteroids[i]<0) {
            i++;
        }
        int prev = asteroids[i];
        int currp;
        int currn;
        while (i<asteroids.size()-1) {
            if (asteroids[i+1]*prev < 0) {
                int p = i;
                int n = i+1;
                //cout << p;
                currp = asteroids[p];
                currn = asteroids[n];
                while (p>=0 && n<asteroids.size() && currp*currn<=0) {
                    currp = asteroids[p];
                    currn = asteroids[n];
                    if (currp>abs(currn)) {
                        asteroids[n]=0;
                        n++;
                    } else if (currp<abs(currn)) {
                        asteroids[p]=0;
                        p--;
                    } else if (currp==abs(currn)) {
                        asteroids[n]=0;
                        asteroids[p]=0;
                        p=-1;
                    }
                    if (p>=0) {
                        currp = asteroids[p];
                    }
                    if (n < asteroids.size()) {
                        currn = asteroids[n];
                    }
                    //currp = asteroids[p];
                    //currn = asteroids[n];
                }
                i=n;
            } else {
                i++;
                prev=asteroids[i];
            }
        }
        vector<int> ans;
        for (auto i : asteroids) {
            if (i!=0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};