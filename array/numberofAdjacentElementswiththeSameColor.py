class Solution:
    def colorTheArray(self, n: int, queries: List[List[int]]) -> List[int]:
        ans=[]
        arr=[0]*n
        total=0
        for q in queries:
            temp=0
            if q[0]<n-1 and arr[q[0]]>0 and arr[q[0]]==arr[q[0]+1]:
                temp-=1
            if q[0]>0 and arr[q[0]]>0 and arr[q[0]]==arr[q[0]-1]:
                temp-=1
            arr[q[0]]=q[1]
            if q[0]<n-1 and arr[q[0]]>0 and arr[q[0]]==arr[q[0]+1]:
                temp+=1
            if q[0]>0 and arr[q[0]]>0 and arr[q[0]]==arr[q[0]-1]:
                temp+=1
            total+=temp
            ans.append(total)
        return ans