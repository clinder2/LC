#include <vector>
using namespace std;

class Node {
    public:
        Node* children[26];
        bool end;
        vector<int> index;
        Node() {
            end=false;
            for (int i = 0; i<26;i++) {
                children[i]=nullptr;
            }
        }
};
bool compare(const string& a, const string& b) {
    return a.length()<b.length();
}
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Node* root = new Node();
        vector<string> v;
        int start=0;
        int end=0;
        while ((start=sentence.find_first_not_of(' ', end))!=-1) {
            end = sentence.find(' ', start);
            v.push_back(sentence.substr(start, end-start));
        }
        sort(dictionary.begin(), dictionary.end(), compare);
        int index=0;
        for (auto s : v) {
            Node* curr = root;
            for (char c : s) {
                if (curr->children[c-'a']==nullptr) {
                    curr->children[c-'a']=new Node();
                }
                curr->index.push_back(index);
                curr=curr->children[c-'a'];
            }
            //curr->index=index;
            index++;
        }
        bool good=true;
        map<int, int> t;
        for (int i = 0; i < v.size(); i++) {
            t[i]=0;
        }
        for (auto s : dictionary) {
            Node* curr = root;
            good=true;
            for (char c : s) {
                if (curr->children[c-'a']==nullptr) {
                    good=false;
                    break;
                } else {
                    curr=curr->children[c-'a'];
                }
                /* if (good) {
                    for (auto i : curr->index) {
                        v[i] = s;
                    }
                } */
            }
            if (good) {
                for (auto i : curr->index) {
                    if (t[i]==0) {
                        v[i] = s;
                        t[i]=1;
                    }
                }
            }
        }
        string ans = "";
        for (auto s : v) {
            ans += s + " ";
        }
        return ans.substr(0, ans.length()-1);
    }
};