# This is a sample Python script.
from typing import Optional, List


# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.


# first element in preorder is root
# partition the inorder

class Solution:

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if preorder:
            root = TreeNode(preorder[0])
            root_index = inorder.index(preorder[0])
            left_inorder = inorder[:root_index]
            right_inorder = inorder[root_index + 1:]
            left_preorder = preorder[1:1 + root_index]
            right_preorder = preorder[1 + root_index:]
            root.left = self.buildTree(left_preorder, left_inorder)
            root.right = self.buildTree(right_preorder, right_inorder)
            return root
        else:
            return None


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    s = Solution()
    s.buildTree([3, 9, 20, 15, 7], [9, 3, 15, 20, 7])


    print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
