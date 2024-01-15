from typing import List

class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
        self.oldColor = -1
        self.newColor = -1
        self.img = [[]]
        
    def isValid(self, i, j):
        return i>=0 and i<self.m and j>=0 and j<self.n and self.img[i][j] == self.oldColor 

    def dfs(self, i, j):
        
        self.img[i][j] = self.newColor
        if self.isValid(i+1, j):
            self.dfs(i+1, j)
        if self.isValid(i-1, j):
            self.dfs(i-1, j)
        if self.isValid(i, j+1):
            self.dfs(i, j+1)
        if self.isValid(i, j-1):
            self.dfs(i, j-1)        



    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        self.m, self.n = len(image), len(image[0])
        self.oldColor = image[sr][sc]
        self.img = image
        self.newColor = color
        if image[sr][sc] != color:
            self.dfs(sr, sc)
        return self.img    


if __name__ == '__main__':
    s = Solution()
    image = [[1,1,1],[1,1,0],[1,0,1]]
    sr = 1
    sc = 1
    color = 2
    print(s.floodFill(image, sr, sc, color))
    