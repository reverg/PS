class BSPNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None

    def __str__(self):
        return str(self.key)


class BSPTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if not self.root:
            self.root = BSPNode(key)
        else:
            self._insert_node(self.root, key)

    def _insert_node(self, node, key):
        if key < node.key:
            if node.left is None:
                node.left = BSPNode(key)
                node.left.parent = node
            else:
                self._insert_node(node.left, key)
        else:
            if node.right is None:
                node.right = BSPNode(key)
                node.right.parent = node
            else:
                self._insert_node(node.right, key)

    def inorder_traversal(self):
        traversal = []
        self._inorder_traversal_recursive(self.root, traversal)
        return traversal

    def _inorder_traversal_recursive(self, node, traversal):
        if node:
            self._inorder_traversal_recursive(node.left, traversal)
            traversal.append(str(node))
            self._inorder_traversal_recursive(node.right, traversal)

    def print_tree(self):
        self._print_tree_recursive(self.root, 0)

    def _print_tree_recursive(self, root, level=0, prefix=""):
        if root is not None:
            print(" " * (level * 4) + prefix + str(root.key))
            if root.left is not None or root.right is not None:
                self._print_tree_recursive(root.left, level + 1, "L:")
                self._print_tree_recursive(root.right, level + 1, "R:")


def inOrderSuccess(node):
    if node == None:
        return None

    if node.right != None:
        return leftMostChild(node.right)
    else:
        q = node
        x = q.parent
        while x != None and x.left != q:
            q = x
            x = x.parent
        return str(x)


def leftMostChild(node):
    if node == None:
        return None
    while node.left != None:
        node = node.left
    return node


if __name__ == "__main__":
    tree = BSPTree()
    tree.insert(5)
    tree.insert(3)
    tree.insert(7)
    tree.insert(2)
    tree.insert(4)
    tree.insert(6)
    tree.insert(8)
    tree.insert(9)
    tree.insert(10)

    tree.print_tree()

    print(inOrderSuccess(tree.root.left.left))
    print(inOrderSuccess(tree.root.left.right))
    print(inOrderSuccess(tree.root))

    print(inOrderSuccess(tree.root.right.left))
    print(inOrderSuccess(tree.root.right.right.right))
    print(inOrderSuccess(tree.root.right.right.right.right))
