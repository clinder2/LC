class CustomStack {
public:
    vector<int> s;
    int pointer;
    int maxsize;
    CustomStack(int maxSize) {
        s=*(new vector<int>(maxSize));
        pointer=-1;
        maxsize=maxSize;
    }
    
    void push(int x) {
        if (pointer<maxsize-1) {
            s[++pointer]=x;
        }
    }
    
    int pop() {
        if (pointer==-1) {
            return -1;
        }
        int temp = s[pointer];
        s[pointer--]=0;
        return temp;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, 1+pointer); i++) {
            s[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */