import sys
from Tree import *
from collections import deque


def checkHeight(root):
    if root == None:
        return -1

    leftHeight = checkHeight(root.left)
    if leftHeight == sys.maxsize:
        return sys.maxsize

    rightHeight = checkHeight(root.right)
    if rightHeight == sys.maxsize:
        return sys.maxsize

    heightDiff = leftHeight - rightHeight
    if abs(heightDiff) > 1:
        return sys.maxsize
    else:
        return max(leftHeight, rightHeight) + 1


def isBalanced(root):
    return checkHeight(root) != sys.maxsize


if __name__ == "__main__":
    tree = BinaryTree()
    tree.insert(5)
    tree.insert(3)
    tree.insert(7)
    tree.insert(2)
    tree.insert(4)
    tree.insert(6)
    tree.insert(8)
    tree.insert(9)
    tree.insert(10)

    print(isBalanced(tree.root))
    tree.print_tree()
