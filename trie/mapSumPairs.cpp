struct node {
    int sum;
    vector<node*> next=*(new vector<node*>(26));
    node(int s) {
        sum=s;
    }
};

class Trie {
public:
    node* root = new node(0);
    map<string, int> m;
    Trie() {}
    void insert(string s, int v) {
        int add=v;
        if (m[s]) {
            add-=m[s];
        }
        m[s]=v;
        node* curr=root;
        for (auto c : s) {
            int i=c-'a';
            //cout<<i<<" ";
            if (curr->next[i]!=NULL) {
                curr->next[i]->sum+=add;
                curr=curr->next[i];
            } else {
                curr->next[i]=new node(add);
                curr=curr->next[i];
            }
        }
    }
    int find(string p) {
        node* curr=root;
        for (auto c : p) {
            int i=c-'a';
            if (curr->next[i]!=NULL) {
                curr=curr->next[i];
            } else {
                return 0;
            }
        }
        return curr->sum;
    }
};

class MapSum {
public:
    Trie t=*(new Trie());
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        t.insert(key, val);
    }
    
    int sum(string prefix) {
        return t.find(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */