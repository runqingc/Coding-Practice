# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def __init__(self):
        self.val = ""
        self.buffer = ""
        self.cnt = 0
        self.de_list = []
        self.de_pre = []
        self.de_in = []
        self.de_cnt = 0

    def pre_order(self, root):
        if root is not None:
            self.val += str(root.val + 1000).zfill(4)
            self.buffer += str(self.cnt).zfill(4)
            root.val = self.cnt
            self.cnt += 1
            self.pre_order(root.left)
            self.pre_order(root.right)

    def in_order(self, root):
        if root is not None:
            self.in_order(root.left)
            self.buffer += str(root.val).zfill(4)
            self.in_order(root.right)

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        self.pre_order(root)
        self.in_order(root)
        return str(self.cnt).zfill(5) + self.val + self.buffer

    # return TreeNode
    def build_tree(self, pre_order, in_order):
        root = None
        if pre_order:
            root = TreeNode(self.de_list[pre_order[0]])
            root_index = in_order.index(pre_order[0])
            root.left = self.build_tree(pre_order[1:1 + root_index], in_order[:root_index])
            root.right = self.build_tree(pre_order[1 + root_index:], in_order[root_index + 1:])
        return root

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        self.de_cnt = int(data[:5])
        for i in range(0, self.de_cnt):
            self.de_list.append(int(data[5 + i * 4:9 + i * 4]) - 1000)
        for i in range(0, self.de_cnt):
            self.de_pre.append(int(data[5 + 4 * self.de_cnt + 4 * i:9 + 4 * self.de_cnt + 4 * i]))
            self.de_in.append(int(data[5 + 8 * self.de_cnt + 4 * i:9 + 8 * self.de_cnt + 4 * i]))
        root = self.build_tree(self.de_pre, self.de_in)
        return root


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    t1 = TreeNode(1)
    t2 = TreeNode(2)
    t3 = TreeNode(3)
    t4 = TreeNode(4)
    t5 = TreeNode(5)
    t1.left = t2
    t1.right = t3
    t3.left = t4
    t3.right = t5
    ser = Codec()
    deser = Codec()
    data = ser.serialize(t1)
    print(data, end='\n')
    print(deser.deserialize(data))

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
