class Solution:
    arr=[]
    base=""
    def perm(self, m, i, s, lim):
        if i>=lim:
            self.arr.append(s)
        elif i in m.keys():
            for j in m[i]:
                self.perm(m, i+1, s+j, lim)
        else:
            #print(i, self.base, lim)
            self.perm(m, i+1, s+self.base[i], lim)
    def expand(self, s: str) -> List[str]:
        m={}
        i=0
        j=0
        self.arr=[]
        self.base=""
        while j <len(s):
            if s[j]!="{":
                self.base+=s[j]
                i+=1
                j+=1
            else:
                m[i]=[]
                while s[j]!="}":
                    j+=1
                    if s[j]!="," and s[j]!="}":
                        m[i].append(s[j])
                j+=1
                i+=1
                self.base+="0"
        self.perm(m,0,"",i)
        self.arr.sort()
        return self.arr
