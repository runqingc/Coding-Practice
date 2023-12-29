# This is a sample Python script.
from typing import Optional


# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def __init__(self):
        self.__result = True

    def inOrder(self, p, q):
        if self.__result:
            if (p is not None and q is None) or (p is None and q is not None):
                self.__result = False
            elif p is not None and q is not None:
                if p.val != q.val:
                    self.__result = False
                else:
                    self.inOrder(p.left, q.left)
                    self.inOrder(p.right, q.right)

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        self.inOrder(p, q)
        return self.__result


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi("Long time no see bro! I am now learning python again : )")



# See PyCharm help at https://www.jetbrains.com/help/pycharm/
