class Solution:
    def longestPalindrome(self, s: str) -> int:
        dict = {}
        for c in s:
            if c not in dict:
                dict[c] = 1
            else:
                dict[c] += 1

        even = 0
        odd = 0
        for char, count in dict.items():
            if count%2==0:
                even += count
            else:
                even += count-1
                odd = 1

        return even+odd        

if __name__ == "__main__":
    solution = Solution()
    print(solution.longestPalindrome("abbbccccddddd"))                    