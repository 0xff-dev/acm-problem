# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __str__(self):
        return '<{} {}>'.format(self.start, self.end)

    __repr__ = __str__

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) == 0:
            return []
        if len(intervals) == 1:
            return intervals
        res = []
        del_indexs = []
        intervals.sort(key=lambda x: x.end, reverse=True)
        print(intervals)
        for index in range(len(intervals)-1):
            if intervals[index+1].start<=intervals[index].end or intervals[index].start>=intervals[index+1].end:
                if intervals[index+1].end < intervals[index].start:
                    continue
                else:
                    intervals[index+1].start = min(intervals[index].start, intervals[index+1].start)
                    intervals[index+1].end = max(intervals[index].end, intervals[index+1].end)
                    intervals[index] = None
                    del_indexs.append(index)
        print(del_indexs)
        for index, data in enumerate(del_indexs):
            del intervals[data-index]
        return intervals

    def __merger(self, intervals):
        # 这是报告的解法, 我想的是反向排序....机器尴尬
        merged = []
        intervals.sort(lambda x: x.start)
        for interval in intervals:
            if not merged or merged[-1].end<interval.start:
                merged.append(interval)
            else:
                merged[-1].end = max(merged[-1].end, interval.end)
        return merged


def generate(nums_tuple: list):
    res = []
    for data in nums_tuple:
        res.append(Interval(data[0], data[1]))
    return res

obj = Solution()
res = obj.merge(generate([[1,3], [2,6], [8,10], [15, 18]]))
print(res)

t = obj.merge(generate([[4,5],[2,4],[4,6],[3,4],[0,0],[1,1],[3,5],[2,2]]))
print(t)

d = obj.merge(generate([[2,3],[4,5],[6,7],[8,9],[1,10]]))
print(d)