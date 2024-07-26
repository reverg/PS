from Tree import *


def containsTree(t1, t2):
    if t2.root == None:
        return True
    else:
        return subTree(t1.root, t2.root)


def subTree(r1, r2):
    if r1 == None:
        return False
    elif r1.key == r2.key and matchTree(r1, r2):
        return True
    return subTree(r1.left, r2) or subTree(r1.right, r2)


def matchTree(r1, r2):
    if r1 == None and r2 == None:
        return True
    elif r1 == None or r2 == None:
        return False
    elif r1.key != r2.key:
        return False
    else:
        return matchTree(r1.left, r2.left) and matchTree(r1.right, r2.right)


if __name__ == "__main__":
    tree1 = BinaryTree()
    tree1.insert(2)
    tree1.insert(3)
    tree1.insert(1)
    tree1.insert(0)
    tree1.insert(4)
    tree1.insert(5)

    tree2 = BinaryTree()
    tree2.insert(3)
    tree2.insert(4)
    tree2.insert(5)
    

    if containsTree(tree1, tree2):
        print("t2 is a subtree of t1")
    else:
        print("t2 is not a subtree of t1")
