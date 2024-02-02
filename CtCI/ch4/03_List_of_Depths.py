from Tree import *
from collections import deque


def createLevelLinkedList(root):
    result = []
    curr_level = []
    if(root != None):
        curr_level.append(root)
    
    while curr_level:
        result.append([str(curr_elem.key) for curr_elem in curr_level])
        parents = curr_level
        curr_level = []
        for parent in parents:
            if parent.left:
                curr_level.append(parent.left)
            if parent.right:
                curr_level.append(parent.right)
    return result
    
    
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
    
    level_list = createLevelLinkedList(tree.root)
    print(level_list)
    tree.print_tree()