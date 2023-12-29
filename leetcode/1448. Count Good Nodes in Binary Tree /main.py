# This is a sample Python script.

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

    def __init__(self, numGoodNode=0):
        self.__numGoodNode = numGoodNode

    def preOrder(self, root: TreeNode, max_value):
        if root.val >= max_value:
            self.__numGoodNode += 1
            max_value = root.val

        if root.left:
            self.preOrder(root.left, max_value)
        if root.right:
            self.preOrder(root.right, max_value)

    def goodNodes(self, root: TreeNode) -> int:
        if root:
            self.preOrder(root, root.val)
        return self.__numGoodNode


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    t1 = TreeNode(3)
    t2 = TreeNode(3)
    t3 = TreeNode(4)
    t4 = TreeNode(2)
    t1.left = t2
    t2.left = t3
    t2.right = t4

    s = Solution()
    print(s.goodNodes(t1))



# See PyCharm help at https://www.jetbrains.com/help/pycharm/
