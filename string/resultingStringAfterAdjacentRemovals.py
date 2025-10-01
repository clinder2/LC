class Solution:
    def resultingString(self, s: str) -> str:
        arr=[]
        for c in s:
            good=True
            if arr and (abs(ord(c)-ord(arr[-1]))==1 or abs(ord(c)-ord(arr[-1]))==25):
                #print(arr, c, ord(arr[-1]))
                arr.pop()
                good=False
            if good:
                arr.append(c)
        return "".join(arr)