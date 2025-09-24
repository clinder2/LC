class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        st=s
        s=[]
        n=len(st)
        for i in range(n):
            if st[i]=='(':
                s.append(-1)
            else:
                temp=0
                while len(s) and s[-1]!=-1:
                    temp+=s[-1]
                    s.pop()
                if len(s) and s[-1]==-1:
                    s.pop()
                    if temp>0:
                        s.append(2*temp)
                    else:
                        s.append(1)
        ans=0
        for i in s:
            ans+=i
        return ans