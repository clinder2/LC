class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        ans=0
        l=intervals[0][0]
        r=intervals[0][1]
        for i in range(1,len(intervals)):
            if intervals[i][0]>l and intervals[i][1]<=r:
                ans+=1
            elif intervals[i][0]==l and intervals[i][1]>=r:
                r=intervals[i][1]
                ans+=1
            else:
                l=intervals[i][0]
                r=intervals[i][1]
        return len(intervals)-ans