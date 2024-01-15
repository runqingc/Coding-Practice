# The isBadVersion API is already defined for you.
def isBadVersion(version: int) -> bool:
    return int%2==0

class Solution:
    def __init__(self):
        self.bad = -1
        
    def binarySearch(self, i, j):
        if self.bad > 0 :
            return
        mid = (i+j)//2
        if isBadVersion(mid):
            if (mid==0 or not isBadVersion(mid-1)):
                self.bad = mid
                return 
            else:
                self.binarySearch(i, mid-1)
        else:
            self.binarySearch(mid+1, j)
        
        

    def firstBadVersion(self, n: int) -> int:
        if n==1:
            return 1
        self.binarySearch(1, n)
        return self.bad
    

if __name__ == "__main__":
    solution = Solution()
    solution.firstBadVersion(3)