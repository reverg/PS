from Tree import *


def createMinimalBST(arr):
    mbst = BinaryTree()
    mbst.root = createMinimalBSTHelp(arr, 0, len(arr) - 1)
    return mbst


def createMinimalBSTHelp(arr, start, end):
    if end < start:
        return None

    mid = (start + end) // 2
    n = BinaryTreeNode(arr[mid])
    n.left = createMinimalBSTHelp(arr, start, mid - 1)
    n.right = createMinimalBSTHelp(arr, mid + 1, end)
    return n


arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
tree = createMinimalBST(arr)
traversal = tree.inorder_traversal()
tree.print_tree()
