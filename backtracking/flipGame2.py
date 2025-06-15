class Solution:
    def canWin(self, currentState: str) -> bool:
        m={}
        arr=[]
        s=""
        for a in currentState:
            if a=='+':
                s+='+'
            else:
                arr.append(str(s))
                s=""
        if len(s)>0:
            arr.append(str(s))
        
        def back(arr):
            l=tuple(arr)
            if l in m:
                return m[l]
            for s in range(len(arr)):
                for i in range(len(arr[s])-1):
                    s1=arr[s][:i]
                    s2=arr[s][i+2:]
                    a=back(arr[:s]+arr[s+1:]+[s1,s2])
                    if not a:
                        m[l]= not a
                        return not a
            m[l]=False
            return False
        return back(arr)