from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.sort()
        ans = []
        # find the first loop that will be affected
        for interval in intervals:
            if newInterval == []:
                ans.append(interval)
            else:
                if interval[-1] < newInterval[0]:
                    ans.append(interval)
                elif newInterval[-1] < interval[0]:
                    ans.append(newInterval)
                    ans.append(interval)
                    newInterval = []
                else:
                    newInterval[0] = min(newInterval[0], interval[0])
                    newInterval[1] = max(newInterval[1], interval[1])   

        if newInterval != []:
            ans.append(newInterval)
        return ans

if __name__ == "__main__":
    solution = Solution()
    test_intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
    new_interval = [4, 8]
    result = solution.insert(test_intervals, new_interval)
    print(result)  # This will print the result of your function