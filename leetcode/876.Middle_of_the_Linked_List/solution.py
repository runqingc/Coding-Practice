from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        l = 0
        tmp = head
        while tmp!=None:
            l += 1
            tmp = tmp.next
        target = l//2 +1
        l = 0
        tmp = head
        while tmp!=None:
            l += 1
            if l == target:
                return tmp
            tmp = tmp.next
        return head
        



if __name__ == "__main__":
    s = Solution()
